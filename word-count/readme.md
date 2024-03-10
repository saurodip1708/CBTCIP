# Word Count Program

This C program is designed to count the number of words in a text file provided by the user.

## Features

- Prompts the user to enter the name of the text file to be processed.
- Opens the specified file for reading.
- Reads the file line by line and counts the number of words.
- Words are considered to be separated by spaces, tabs, or newline characters.
- Displays the total word count along with the file name.

## Usage

1. Compile the program using a C compiler.
2. Run the compiled executable.
3. Enter the name of the text file when prompted.
4. The program will read the file and display the word count along with the file name.

## Example

```
Enter the name of the text file: example.txt
The number of words in the file 'example.txt' is: 123
```

## Code Structure

The program is divided into the following sections:

1. **Includes**: The necessary header files `stdio.h` and `string.h` are included for file I/O and string manipulation functions, respectively.

2. **Constants**: The `max_file_len` and `max_file_name_len` constants define the maximum length of a line in the file and the maximum length of the file name, respectively.

3. **Main Function**:
   - Declares variables for file pointer, line buffer, file name, word count, and word flag.
   - Prompts the user to enter the file name and reads it using `fgets()`.
   - Opens the specified file using `fopen()` in read mode.
   - Reads the file line by line using `fgets()` and processes each line.
   - Counts the words by iterating over each character in the line and checking for word separators.
   - Closes the file using `fclose()`.
   - Prints the word count along with the file name.

## Notes

- The program assumes that words are separated by spaces, tabs, or newline characters. If you need to handle other word separators or have additional requirements, you may need to modify the code accordingly.
- The maximum line length and file name length are defined by the `max_file_len` and `max_file_name_len` constants, respectively. You can adjust these values as needed.
- Error handling is implemented to handle cases where the file cannot be opened.