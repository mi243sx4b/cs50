#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(char text[]) {
	int ret = 0;
	for (int i = 0; i < strlen(text); i++) {
		if ((65 <= text[i] && text[i] <= 90) || 97 <= text[i] && text[i] <= 122) ret++;
	}
	return ret;
}

int count_words(char text[]) {
	int ret = 1;
	for(int i = 0; i < strlen(text); i++) {
		if (text[i] == ' ') ret++;
	}
	return ret;
}

int count_sentences(char text[]) {
	int ret = 0;
	for (int i = 0; i < strlen(text); i++) {
		if (text[i] == '.' || text[i] == '?' || text[i] == '!') ret++;
	}
	return ret;
}

void main() {
	char text[1000000];
	printf("Text: ");
	fgets(text, 1000000, stdin);
	int letter = count_letters(text);
	int word = count_words(text);
	int sentence = count_sentences(text);
	double L = ((double)letter / (double)word) * 100.0;
	double S = ((double)sentence / (double)word) * 100.0;
	double index = 0.0588 * L - 0.296 * S - 15.8;
	index = round(index);
	if (index < 1) printf("Before Grade 1\n");
	else if (index >= 16) printf("Grade 16+\n");
	else printf("Grade %d\n", (int)index);
}

