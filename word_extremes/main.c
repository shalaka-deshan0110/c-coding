#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_vowels(char *word) {
    int count = 0;

    for (int i = 0; i < strlen(word); i++) {
        char c = tolower(word[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
    }
    return count;
}

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {

    char word[100];
    char smallest_word[100], largest_word[100];
    int smallest_vowels = 0, largest_vowels = 0;

    printf("Enter a word (or 'qa!' to stop): ");

    scanf("%99s", word);

    if (strcmp(word, "qa!") == 0) {
        printf("No words entered.\n");
        return 0;
    }

    strcpy(smallest_word, word);
    strcpy(largest_word, word);
    smallest_vowels = count_vowels(smallest_word);
    largest_vowels = count_vowels(largest_word);
    
    while (strcmp(word, "qa!") != 0) {
        char lower_case_word[100];
        char lower_case_smallest[100];
        char lower_case_largest[100];

        strcpy(lower_case_word, word);
        to_lowercase(lower_case_word);

        strcpy(lower_case_smallest, smallest_word);
        to_lowercase(lower_case_smallest);

        strcpy(lower_case_largest, largest_word);
        to_lowercase(lower_case_largest);

        if (strlen(word) == strlen(smallest_word) && strcmp(lower_case_word, lower_case_smallest) < 0) {
            strcpy(smallest_word, word);
            smallest_vowels = count_vowels(smallest_word);
        } else if (strlen(word) < strlen(smallest_word)) {
            strcpy(smallest_word, word);
            smallest_vowels = count_vowels(smallest_word);
        }

        if (strlen(word) == strlen(largest_word) && strcmp(lower_case_word, lower_case_largest) > 0) {
            strcpy(largest_word, word);
            largest_vowels = count_vowels(largest_word);
        } else if (strlen(word) > strlen(largest_word)) {
            strcpy(largest_word, word);
            largest_vowels = count_vowels(largest_word);
        }

        printf("Enter a word (or 'qa!' to stop): ");
        scanf("%99s", word);
    }

    printf("Smallest word: %s (vowels: %d)\n", smallest_word, smallest_vowels);
    printf("Largest word: %s (vowels: %d)\n", largest_word, largest_vowels);

    return 0;
}











