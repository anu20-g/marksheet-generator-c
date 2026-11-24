/*
 * Student Marksheet Generator
 * Team 1
 * Concepts: Arrays, Functions, Conditional Statements
 */
#include <stdio.h>

char calculateGrade(float pct) {
    if (pct >= 90.0) return 'A';
    if (pct >= 75.0) return 'B';
    if (pct >= 60.0) return 'C';
    if (pct >= 40.0) return 'D';
    return 'F';
}

int main() {
    char name[50], roll[20];
    const char *subjects[5] = {"Mathematics", "Physics", "Chemistry", "Computer Science", "English"};
    float marks[5];
    float total = 0.0, percentage;
    int isPass = 1;

    printf("=== ACADEMIC MARKSHEET GENERATOR ===\n");
    printf("Enter Student Name: ");
    fgets(name, sizeof(name), stdin);
    printf("Enter Roll Number: ");
    scanf("%s", roll);

    printf("\nEnter marks for 5 subjects (out of 100):\n");
    for (int i = 0; i < 5; i++) {
        printf("%-18s: ", subjects[i]);
        scanf("%f", &marks[i]);
        if (marks[i] < 35.0) isPass = 0;
        total += marks[i];
    }

    percentage = total / 5.0;
    char grade = calculateGrade(percentage);

    printf("\n================== STUDENT MARKSHEET ==================\n");
    printf("Student Name : %s", name);
    printf("Roll Number  : %s\n", roll);
    printf("-------------------------------------------------------\n");
    printf("%-20s %-12s %-10s\n", "Subject", "Max Marks", "Scored");
    printf("-------------------------------------------------------\n");
    for (int i = 0; i < 5; i++) {
        printf("%-20s %-12d %-10.2f\n", subjects[i], 100, marks[i]);
    }
    printf("-------------------------------------------------------\n");
    printf("Total Scored : %.2f / 500\n", total);
    printf("Percentage   : %.2f%%\n", percentage);
    printf("Final Grade  : %c\n", grade);
    printf("Status       : %s\n", isPass ? "PASSED" : "FAILED (Subject score < 35)");
    printf("=======================================================\n");

    return 0;
}
