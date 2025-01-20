#include <stdio.h>
#include <string.h>

void reverseWords(char sen[]) {
    char *ptr = sen;

    while (*ptr != '\0') {
        ptr++;
    }
    ptr--; 

    int firstWord = 1;

    while (ptr >= sen) {
        while (ptr >= sen && *ptr == ' ') {
            ptr--;
        }

        char *end = ptr;

        while (ptr >= sen && *ptr != ' ') {
            ptr--;
        }
        if (!firstWord) {
            printf(" ");
        }
        firstWord = 0;

        for (char *temp = ptr + 1; temp <= end; temp++) {
            printf("%c", *temp);
        }
    }
}

int main() {
    char sentence[100];
    scanf("%[^\n]%*c", sentence); 
    reverseWords(sentence);
    return 0;
}

