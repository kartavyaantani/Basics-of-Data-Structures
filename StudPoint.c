#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold student information
struct Student {
    char name[50];
    int rollNumber;
    float cgpa;
};

// Function to read student information
void readStudent(struct Student *student) {
    printf("Enter name: ");
    scanf("%s", student->name);

    printf("Enter roll number: ");
    scanf("%d", &student->rollNumber);

    printf("Enter CGPA: ");
    scanf("%f", &student->cgpa);
}

// Function to display student information
void displayStudent(const struct Student *student) {
    printf("Name: %s\n", student->name);
    printf("Roll Number: %d\n", student->rollNumber);
    printf("CGPA: %.2f\n", student->cgpa);
}

// Comparison function for sorting students by roll number
int compareByRollNumber(const void *a, const void *b) {
    return ((struct Student *)a)->rollNumber - ((struct Student *)b)->rollNumber;
}

int main() {
    int numStudents;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    // Allocate memory for an array of Student structures
    struct Student *students = (struct Student *)malloc(numStudents * sizeof(struct Student));

    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Read student information
    for (int i = 0; i < numStudents; i++) {
        printf("Enter details for student %d:\n", i + 1);
        readStudent(&students[i]);
    }

    // Sort students by roll number
    qsort(students, numStudents, sizeof(struct Student), compareByRollNumber);

    // Display sorted student information
    printf("\nSorted student list:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("\nDetails of student %d:\n", i + 1);
        displayStudent(&students[i]);
    }

    // Free allocated memory
    free(students);

    return 0;
}

