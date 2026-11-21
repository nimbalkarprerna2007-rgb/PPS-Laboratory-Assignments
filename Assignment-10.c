#include <stdio.h>

// Function to check if the given year is a leap year
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Sakamoto's algorithm to return the day of the week (0 = Sunday, 6 = Saturday)
int getStartingDay(int day, int month, int year) {
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    if (month < 3) {
        year -= 1;
    }
    return (year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7;
}

// Function to print the 12-month calendar for the given year
void printYearlyCalendar(int year) {
    const char *months[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Adjust February for leap years
    if (isLeapYear(year)) {
        daysInMonth[1] = 29;
    }

    printf("\n============== CALENDAR - %d ==============\n", year);

    for (int month = 0; month < 12; month++) {
        // Print month header
        printf("\n  ------------ %s ------------\n", months[month]);
        printf(" Sun Mon Tue Wed Thu Fri Sat\n");

        // Find the starting weekday for the 1st of the current month
        int currentDay = getStartingDay(1, month + 1, year);

        // Print leading spaces for the first week
        for (int space = 0; space < currentDay; space++) {
            printf("    ");
        }

        // Print all days of the month
        for (int day = 1; day <= daysInMonth[month]; day++) {
            printf("%4d", day);

            // Move to a new line after Saturday
            if (++currentDay > 6) {
                currentDay = 0;
                printf("\n");
            }
        }

        // Ensure a clean newline at the end of the month
        if (currentDay != 0) {
            printf("\n");
        }
    }
}

int main() {
    int year;

    printf("Enter a year (e.g., 2026): ");
    if (scanf("%d", &year) != 1 || year < 1) {
        printf("Invalid input. Please enter a valid positive year.\n");
        return 1;
    }

    printYearlyCalendar(year);

    return 0;
}
