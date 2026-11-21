#include <stdio.h>

// Defining the student structure
struct student {
    int roll_no;
    char name[50];
    int marks[3];
    int total;
    float percentage;
};

int main() {
    int i, j, n;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Creating an array of structures
    struct student s[n];

    // Reading student records
    for (i = 0; i < n; i++) {
        printf("\nEnter details for Student %d:\n", i + 1);

        printf("Enter Roll Number: ");
        scanf("%d", &s[i].roll_no);

        printf("Enter Name: ");
        scanf("%s", s[i].name);

        s[i].total = 0;
        printf("Enter marks for 3 subjects: \n");
        for (j = 0; j < 3; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%d", &s[i].marks[j]);
            s[i].total += s[i].marks[j];
        }

        // Calculating percentage
        s[i].percentage = (float)s[i].total / 3.0;
    }

    // Displaying the records and results
    printf("\n%-10s %-20s %-15s %-10s %-10s\n", "Roll No", "Name", "Sub Marks", "Total", "Percentage");
    printf("-----------------------------------------------------------------------\n");

    for (i = 0; i < n; i++) {
        printf("%-10d %-20s %d, %d, %d      %-10d %-10.2f\n",
               s[i].roll_no,
               s[i].name,
               s[i].marks[0], s[i].marks[1], s[i].marks[2],
               s[i].total,
               s[i].percentage);
    }

    return 0;
}
