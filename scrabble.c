#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Points assigned to each letter of the alphabet
int POINTS[] = { 1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10 };

int compute_score(char word[]);

int main(void) {
    // Get input words from both players
    char word1[100];
    printf("Player 1: ");
    scanf_s("%s", word1, sizeof(word1));
    
    char word2[100];
    printf("Player 2: ");
    scanf_s("%s", word2, sizeof(word2));
    

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2) printf("Player 1 wins!\n");
    else if (score1 < score2) printf("Player 2 wins!\n");
    else printf("Tie!\n");
}

int compute_score(char word[])
{
    // TODO: Compute and return score for string
    int score = 0;
    for (int i = 0; i < strlen(word); i++) {
        if ((65 <= word[i] && word[i] <= 90) || (97 <= word[i] && word[i] <= 122)) {
            int indx = (word[i] - 'A') % 32;
            score += POINTS[indx];
        }
    }
    return score;
}
