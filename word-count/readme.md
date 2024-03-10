# Word, Line, and Character Counter in C

This C program counts the number of words, lines, and characters in a given text file. It prompts the user to enter the filename, reads the file content, and calculates the requested statistics.

## Features

- **File Input**: The program prompts the user to enter the filename of the text file to be analyzed.
- **Word Count**: It counts the number of words in the file based on whitespace characters (space, tab, newline, etc.).
- **Line Count**: It counts the number of lines in the file by keeping track of newline characters.
- **Character Count**: It counts the total number of characters in the file, including whitespace characters.
- **Error Handling**: If the specified file cannot be opened, the program will print an error message and exit gracefully.

## Usage

1. Compile the C source code.
2. Run the compiled program.
3. When prompted, enter the filename of the text file you want to analyze (including the file extension).
4. The program will display the word, line, and character counts for the specified file.

## Code Explanation

1. The program includes necessary header files: `stdio.h` for input/output operations, `stdlib.h` for memory allocation functions, `string.h` for string manipulation, and `ctype.h` for character classification functions.
2. The `MAX_FILENAME_LENGTH` macro defines the maximum length of the filename that can be entered by the user.
3. The `countWordsLinesChars` function takes a filename and three pointers to integers as arguments. It opens the file, reads it character by character, and updates the word, line, and character counts accordingly. The function uses a flag `inWord` to determine if the current character is part of a word or not.
4. In the `main` function, the user is prompted to enter the filename. The `fgets` function is used to read the filename from the user, and the newline character is removed using the `strcspn` and null terminator.
5. The `countWordsLinesChars` function is called with the provided filename and pointers to `words`, `lines`, and `chars` variables.
6. Finally, the program prints the calculated statistics for words, lines, and characters.

## Note

This program assumes that the input file is a plain text file and that words are separated by whitespace characters (space, tab, newline). It does not handle additional cases such as punctuation or special characters within words.