#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int choice;
    char str1[100], str2[100], result[200];

    while (1) {
        printf("\n=====================================");
        printf("\n    STRING OPERATIONS MENU (TPoint) ");
        printf("\n=====================================");
        printf("\n1. Find Length of a String (strlen)");
        printf("\n2. Copy String (strcpy)");
        printf("\n3. Concatenate Strings (strcat)");
        printf("\n4. Compare Two Strings (strcmp)");
        printf("\n5. Reverse a String (strrev/manual)");
        printf("\n6. Convert to Uppercase (strupr)");
        printf("\n7. Convert to Lowercase (strlwr)");
        printf("\n8. Exit");
        printf("\n=====================================");
        printf("\nEnter your choice (1-8): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

        switch (choice) {
            case 1:
                printf("\nEnter a string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0';

                printf("Length of the string: %lu\n", (unsigned long)strlen(str1));
                break;

            case 2:
                printf("\nEnter the source string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0';

                strcpy(str2, str1);
                printf("Copied String (Destination): %s\n", str2);
                break;

            case 3:
                printf("\nEnter the first string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0';

                printf("Enter the second string: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = '\0';

                strcpy(result, str1);
                strcat(result, str2);
                printf("Concatenated String: %s\n", result);
                break;

            case 4:
                printf("\nEnter the first string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0';

                printf("Enter the second string: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = '\0';

                int cmp = strcmp(str1, str2);
                if (cmp == 0) {
                    printf("Both strings are equal.\n");
                } else if (cmp > 0) {
                    printf("First string is greater than the second string.\n");
                } else {
                    printf("First string is smaller than the second string.\n");
                }
                break;

            case 5:
                printf("\nEnter a string to reverse: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0';

                // Note: strrev() is non-standard and not available in all compilers (like GCC)
                // We use a safe standard approach or simulate its behavior loop-style
                int len = strlen(str1);
                for (int i = 0; i < len / 2; i++) {
                    char temp = str1[i];
                    str1[i] = str1[len - i - 1];
                    str1[len - i - 1] = temp;
                }
                printf("Reversed String: %s\n", str1);
                break;

            case 6:
                printf("\nEnter a string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0';

                // standard compiler safe loop implementation of upper case conversion
                for (int i = 0; str1[i] != '\0'; i++) {
                    if (str1[i] >= 'a' && str1[i] <= 'z') {
                        str1[i] = str1[i] - 32;
                    }
                }
                printf("Uppercase String: %s\n", str1);
                break;

            case 7:
                printf("\nEnter a string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0';

                // standard compiler safe loop implementation of lower case conversion
                for (int i = 0; str1[i] != '\0'; i++) {
                    if (str1[i] >= 'A' && str1[i] <= 'Z') {
                        str1[i] = str1[i] + 32;
                    }
                }
                printf("Lowercase String: %s\n", str1);
                break;

            case 8:
                printf("\nExiting the program. Goodbye!\n");
                exit(0);

            default:
                printf("\nInvalid choice! Please select a valid option from the menu.\n");
        }
    }
    return 0;
}
