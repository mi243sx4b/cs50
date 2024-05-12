#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
	char key[100];
	scanf_s("%s", key, sizeof(key));
	if (strlen(key) != 26) {
		printf("Key must contain 26 characters\n");
		return 0;
	}
	for (int i = 0; i < 26; i++) {
		if (!((65 <= key[i] && key[i] <= 90) || (97 <= key[i] && key[i] <= 122))) {
			printf("Key must contain 26 alphabets\n");
			return 0;
		}
	}
	for (int i = 0; i < 26; i++) {
		if (97 <= key[i] && key[i] <= 122) {
			key[i] -= 32;
		}
	}

	printf("plaintext: ");
	char ptxt[100];
	char enter[1];
	scanf_s("%c", enter, sizeof(enter));
	fgets(ptxt, strlen(ptxt), stdin);
	printf("ciphertext: ");
	for (int i = 0; i < strlen(ptxt); i++) {
		if (65 <= ptxt[i] && ptxt[i] <= 90) {
			int indx = ptxt[i] - 'A';
			printf("%c", key[indx]);
		}
		else if (97 <= ptxt[i] && ptxt[i] <= 122) {
			int indx = ptxt[i] - 'a';
			printf("%c", key[indx] + 32);
		}
		else {
			printf("%c", ptxt[i]);
		}
	}

	return 0;
}

