#include <stdio.h>
#include <string.h>

//Luhn algorithm
bool Luhn(char input[100], int length) {
    int sum = 0;
    for (int i = 0; i < length; i += 2) {
        int tmp = (input[i] - '0') * 2;
        tmp = tmp / 10 + tmp % 10;
        sum += tmp;
    }
    for (int i = length - 1; i >= 0; i -= 2) {
        sum += input[i] - '0';
    }
    if (sum % 10 == 0) return 1;
    return 0;
}

//check if input is number
bool isNumber(char input[100], int length) {
    for (int i = 0; i < length; i++) {
        int num = input[i] - '0';
        if (num < 0 || 9 < num) {
            printf("INVALID\n");
            return 0;
        }
    }
    return 1;
}

int main(void){
    //input
    while (1) {
        char input[100];
        printf("Number: ");
        scanf_s("%s", input, sizeof(input));
        int length = strlen(input);

        //check
        //American Express
        if (length == 15) {
            if (!isNumber(input, length)) continue;
            if (input[0] - '0' == 3 && (input[1] - '0' == 4 || input[1] - '0' == 7)) {
                if (Luhn(input, length)) {
                    printf("American Express\n");
                    return 0;
                }
            }
        }

        //MasterCard
        else if (length == 16) {
            if (!isNumber(input, length)) continue;
            if (input[0] - '0' == 5 && (input[1] - '0' == 1 || input[1] - '0' == 2 || input[1] - '0' == 3 || input[1] - '0' == 4 || input[1] - '0' == 5)) {
                if (Luhn(input, length)) {
                    printf("MasterCard\n");
                    return 0;
                }
            }
        }

        //Visa
        else if (length == 13 || length == 16) {
            if (!isNumber(input, length)) continue;
            if (input[0] - '0' == 4) {
                if (Luhn(input, length)) {
                    printf("Visa\n");
                    return 0;
                }
            }
        }

        else printf("INVALID\n");
    }
}
