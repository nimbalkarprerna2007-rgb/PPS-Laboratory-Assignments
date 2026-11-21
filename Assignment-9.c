#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *sourceFile, *destFile;
    char sourcePath[100], destPath[100];
    int ch;

    // Get file names from the user
    printf("Enter source file path: ");
    scanf("%99s", sourcePath);

    printf("Enter destination file path: ");
    scanf("%99s", destPath);

    // Open source file in read mode
    sourceFile = fopen(sourcePath, "r");
    if (sourceFile == NULL) {
        printf("Error: Unable to open source file.\n");
        return 1;
    }

    // Open destination file in write mode
    destFile = fopen(destPath, "w");
    if (destFile == NULL) {
        printf("Error: Unable to open or create destination file.\n");
        fclose(sourceFile);
        return 1;
    }

    // Copy contents character by character
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destFile);
    }

    printf("File copied successfully.\n");

    // Close both files to release resources
    fclose(sourceFile);
    fclose(destFile);

    return 0;
}
