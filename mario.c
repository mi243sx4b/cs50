#include <stdio.h>

int main(void)
{
    int num;
    printf("Height:");
    scanf_s("%d", &num);
    printf("\n");

    for (int i = 1; i <= num; i++) {
        for (int j = 0; j < num - i; j++) {
            printf(" ");
        }
        for (int j = 0; j < i; j++) {
            printf("#");
        }
        printf("  ");
        for (int j = 0; j < i; j++) {
            printf("#");
        }
        printf("\n");
    }
}
