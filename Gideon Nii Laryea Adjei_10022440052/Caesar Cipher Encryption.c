#include <stdio.h>
#include <ctype.h>
#include <string.h>

char shift_char(char c, int key) {
    if (isupper(c))
        return ((c - 'A' + key) % 26) + 'A';
    else if (islower(c))
        return ((c - 'a' + key) % 26) + 'a';
    else
        return c;
}

int main() {
    char plaintext[1000];
    int key;

    printf("Enter key: ");
    scanf("%d", &key);
    getchar(); 

    printf("plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("ciphertext: ");
    for (int i = 0; plaintext[i] && plaintext[i] != '\n'; i++) {
        printf("%c", shift_char(plaintext[i], key));
    }
    printf("\n");

    return 0;
}
