#include <stdio.h>
#include <string.h>

void printPaddedString(const char *inputString) {
    int length = strlen(inputString);

    if (length < 2 || length > 10) {
        printf("Input string must be between 2 and 10 characters long.\n");
        return;
    }

    printf("Original String: %s||\n", inputString);

    // Calculate the number of spaces needed for padding
    int spacesNeeded = 10 - length;

    // Print the padded string
    printf("Padded String: ");
    printf("%s", inputString);
    
    for (int i = 0; i < spacesNeeded; ++i) {
        printf(" ");
    }

    printf("||\n");
}

int main() {
    // Example usage
    char test[11] = "Hello";
    printPaddedString(test);
    printPaddedString("Hi");
    printPaddedString("1234567890");
    printPaddedString("Short");

    return 0;
}