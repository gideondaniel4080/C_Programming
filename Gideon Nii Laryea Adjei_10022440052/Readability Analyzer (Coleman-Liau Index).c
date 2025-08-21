#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(const char *text) {
    int count = 0;
    for (int i = 0; text[i]; i++) {
        if (isalpha(text[i])) count++;
    }
    return count;
}

int count_words(const char *text) {
    int count = 1;
    for (int i = 0; text[i]; i++) {
        if (isspace(text[i])) count++;
    }
    return count;
}

int count_sentences(const char *text) {
    int count = 0;
    for (int i = 0; text[i]; i++) {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') count++;
    }
    return count;
}

int main() {
    char text[1000];
    printf("Text: ");
    fgets(text, sizeof(text), stdin);

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    float L = (float)letters / words * 100;
    float S = (float)sentences / words * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;

    if (index < 1)
        printf("Before Grade 1\n");
    else if (index >= 16)
        printf("Grade 16+\n");
    else
        printf("Grade %.0f\n", round(index));

    return 0;
}