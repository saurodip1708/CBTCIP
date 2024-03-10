#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILENAME_LENGTH 100

void countWordsLinesChars(char *filename, int *words, int *lines, int *chars) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open the file %s\n", filename);
        return;
    }

    int inWord = 0;
    *words = 0;
    *lines = 0;
    *chars = 0;

    char c;
    while ((c = fgetc(file)) != EOF) {
        (*chars)++;
        if (c == '\n') {
            (*lines)++;
            inWord = 0;
        } else if (isspace(c)) {
            inWord = 0;
        } else if (!inWord) {
            (*words)++;
            inWord = 1;
        }
    }

    if (inWord) {
        (*words)++;
    }

    if (*chars > 0) {
        (*lines)++;
    }

    fclose(file);
}

int main() {
    char filename[MAX_FILENAME_LENGTH];
    int words, lines, chars;

    printf("Enter the filename: ");
    fgets(filename, MAX_FILENAME_LENGTH, stdin);
    filename[strcspn(filename, "\n")] = '\0'; // Remove newline character

    countWordsLinesChars(filename, &words, &lines, &chars);

    printf("\nFile Statistics:\n");
    printf("Words: %d\n", words);
    printf("Lines: %d\n", lines);
    printf("Characters: %d\n", chars);

    return 0;
}