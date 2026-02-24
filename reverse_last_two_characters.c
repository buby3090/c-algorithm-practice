#include <stdlib.h>
#include <string.h>

char* lastLetters(char* word) {
    
    int len = strlen(word);
    
    // Allocate memory for: char + space + char + null terminator
    char* result = (char*)malloc(4 * sizeof(char));
    
    result[0] = word[len - 1];   // last character
    result[1] = ' ';             // space
    result[2] = word[len - 2];   // second last character
    result[3] = '\0';            // null terminator
    
    return result;
}
