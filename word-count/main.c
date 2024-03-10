#include <stdio.h>
#include <string.h>

#define max_file_len 1000
#define max_file_name_len 100

int main() {
FILE *file;
char line[max_file_len];
    char file_name[max_file_name_len];
int word_count = 0;
int in_word = 0;
  
printf("Enter the name of the text file: ");
    fgets(file_name, max_file_name_len, stdin);
file_name[strcspn(file_name, "\n")] = '\0'; 


 file = fopen(file_name, "r");
    if (file == NULL) {
     printf("Error opening file '%s'.\n", file_name);
return 1;
    }    
while (fgets(line, max_file_len, file) != NULL) {
        int i;
  for (i = 0; i < strlen(line); i++) {
    if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n') {
             in_word = 0;
    } else {
      if (!in_word) {
     word_count++;
            in_word = 1;
         }
         }
     }
    }
 fclose(file);    
 printf("The number of words in the file '%s' is: %d\n", file_name, word_count);
return 0;
}