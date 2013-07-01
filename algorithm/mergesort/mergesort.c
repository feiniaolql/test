#include <stdlib.h>
#include <stdio.h>

#define RECURSIVE

int *read_sequence(char *fname, int *len)
{
	FILE *fp;
	int cnt = 0;
    int *data_buf, *p;

	fp = fopen(fname, "r");
    fscanf(fp, "%d", len);
    data_buf = (int *)malloc((*len) * sizeof(int));    
    p = data_buf;

	while (fscanf(fp, "%d", p) != EOF) {
        p++;
	}
	fclose(fp);
	return data_buf;
}

int save_sequence(char *fname, int *data, int len)
{
	FILE *fp;
    int i;

	fp = fopen(fname, "w");
    for (i = 0; i < len; i++) {
        fprintf(fp, "%5d", data[i]);
        if (i % 15 == 0)
            fprintf(fp, "\n");
    }

    fclose(fp);
    return 0;
}

int merge(int *list, int start, int mid, int end)
{
    int len, i;
    int *buf_a, *buf_b;
    int a_inx, b_inx;

    len = end - start + 1;
    buf_a = (int *)malloc((mid - start + 1 + 1) * sizeof(int));
    buf_b = (int *)malloc((end - mid + 1) * sizeof(int));

    for (i = 0; i < mid -start + 1; i++) 
        buf_a[i] = list[start + i];
    buf_a[i] = ((1L << 31) - 1); // infinite number
    for (i = 0; i < end - mid; i++) 
        buf_b[i] = list[mid + 1 + i];
    buf_b[i] = ((1L << 31) - 1); // infinite number
    
    a_inx = 0;
    b_inx = 0;
    for (i = 0; i < len; i++) {
        if (buf_a[a_inx] <= buf_b[b_inx]) {
            list[start + i] = buf_a[a_inx];
            a_inx++;
        } else {
            list[start + i] = buf_b[b_inx];
            b_inx++;
        }
    }

    free(buf_a);
    free(buf_b);

    return 0;
}

#ifdef RECURSIVE
int mergesort(int *list, int start, int end)
{
    int mid;

    if (start == end)
        return 0;
    else {
        mid = (start + end) / 2;
        mergesort(list, start, mid);
        mergesort(list, mid + 1, end);
        merge(list, start, mid, end);
    }

    return 0;
}

#else
int mergesort(int *list, int start, int end)
{
    int k;
    int len, cnt;

    len = end - start + 1;
    k = 1;

    while ( k < len) {
        cnt = 0;
        while (cnt < len) {
            if (len - cnt >=  2 * k) {
                merge(list, cnt, cnt + k - 1, cnt + 2 * k - 1);
                cnt += 2 * k;
            } else if(len -cnt > k) {
                merge(list, cnt, cnt + k - 1, len - 1);
                cnt = len;
            } else {
                cnt = len;
            }
            printf("cnt = %d\n", cnt);
        }
        k = k * 2;
        printf("k = %d\n", k);
    }

    return 0;
}

#endif

int main(int argc, char **argv)
{
    int *data_buf;
    int len;
    
    printf("open file %s\n", argv[1]);
    data_buf = read_sequence(argv[1], &len);
    printf("len : %d\n", len);
    mergesort(data_buf, 0, len - 1);
    save_sequence(argv[2], data_buf, len);

    //free(data_buf);
    return 0; 
}
