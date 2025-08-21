#include <stdio.h>
#include <string.h>
#include <ctype.h>

char complement(char base) {
    switch (toupper(base)) {
        case 'A': return 'T';
        case 'T': return 'A';
        case 'C': return 'G';
        case 'G': return 'C';
        default: return base;
    }
}

int main() {
    char dna[1000];
    printf("Enter a DNA sequence: ");
    fgets(dna, sizeof(dna), stdin);

    printf("Complement: ");
    for (int i = 0; dna[i] && dna[i] != '\n'; i++) {
        printf("%c", complement(dna[i]));
    }
    printf("\n");

    return 0;
}
