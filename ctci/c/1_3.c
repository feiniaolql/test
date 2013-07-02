#include <stdio.h>
#include <string.h>

int rm_dumplicate_chars(char *str)
{
    int len;
    int i, j;
    int diff;
    int tail;

    len = strlen(str);

/* Solution 1: */
/*
    diff = 0;
    for (i = 0; i < len - 1; i++) {
        diff = 0;
        for (j = i + 1; j < len; j++) {
            if (str[i] == str[j]) {
                diff++;
            } else if (diff > 0) {
                str[j - diff] = str[j];

            }
        }
        len -= diff;
    }
    str[len] = '\0';
*/

/* Solution 2: */
    tail = 1;
    for (i = 1; i < len; i++) {
        for (j = 0; j < tail; j++) {
            if (str[j] == str[i])
                break;
        }
        if (j == tail) {
            str[tail] = str[i];
            tail++;
        }
    }
    str[tail] = '\0';

}

int rm_dumplicate_chars_eff(char *str)
{
    int len;
    char hit[256];
    int i = 0;
    int index = 0;
    int tail = 0;

    len = strlen(str);
    for (i = 0; i < 256; i++) {
        hit[i] = 0;
    }

    for (i = 0; i < len; i++) {
        index = str[i]; 
        hit[index] += 1;
        if (hit[index] <= 1) {
            str[tail++] = str[i];
        }
    }
    str[tail] = '\0';
    
    return 0;
}

int main(int argc, char **argv)
{
    
    char str[100];

    printf("Input the string:\n");
    scanf("%s", str);
    //rm_dumplicate_chars(str);
    rm_dumplicate_chars_eff(str);
    printf("The result: %s\n", str);

    return 0;
}
