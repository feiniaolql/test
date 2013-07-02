#include <stdio.h>

#define N   5

int image[N][N] = {{1,2,3,4,5},
                    {6,7,8,9,10},
                    {11,12,13,14,15},
                    {16,17,18,19,20},
                    {21,22,23,24,25}};

int rotate_image(void)
{
    int i, j;
    int tmp;
    for (i = 0; i < N / 2 + 1; i++) {
        for (j = i; j < N - (i + 1); j++) {
            tmp = image[N - 1 - j][i];
            image[N - 1 - j][i] = image[N - 1 - i][N - 1 - j];
            image[N - 1 - i][N - 1 - j] = image[j][N - 1 - i];
            image[j][N - 1 - i] =  image[i][j];
            image[i][j] = tmp;
        }
    }

}

int main(int argc, char **argv)
{
    int i, j;

    rotate_image();

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%2d ", image[i][j]);        
        }
        printf("\n");
    }

    return 0;
}
