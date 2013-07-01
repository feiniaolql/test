#include <stdio.h>

int main(int argc, char **argv)
{
    char str[100];
    unsigned int flag = 0;
    int i = 0, index = 0;
    
    printf("input the string:\n");
    scanf("%s", str);

    while (str[i] != '\0') {
        index = str[i] - 'a';
        
        if ((flag >> index) & 1) {
            printf("the character %c is not unique\n", str[i]);
            return 1;
        } else
            flag = flag | (1 << index);

        i++;
    }

    printf("the string has all unique characters\n");
    return 0;
}
