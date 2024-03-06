#include <stdio.h>
#include <stdlib.h>

// Structure definitions
struct DOB {
    int day;
    int *month;
    int year;
};

struct STU_INFO {
    int reg_no;
    char *name;
    char *address;
};

struct COLLEGE {
    char *college_name;
    char *university_name;
};

struct STUDENT {
    struct DOB *dob_ptr;
    struct STU_INFO *info_ptr;
    struct COLLEGE *college_ptr;
};

int main() {
    // Allocate memory for STUDENT structure
    struct STUDENT *student_ptr = (struct STUDENT *)malloc(sizeof(struct STUDENT));
    
    // Allocate memory for DOB structure and its members
    student_ptr->dob_ptr = (struct DOB *)malloc(sizeof(struct DOB));
    student_ptr->dob_ptr->month = (int *)malloc(sizeof(int));

    // Allocate memory for STU_INFO structure and its members
    student_ptr->info_ptr = (struct STU_INFO *)malloc(sizeof(struct STU_INFO));
    student_ptr->info_ptr->name = (char *)malloc(50 * sizeof(char));
    student_ptr->info_ptr->address = (char *)malloc(100 * sizeof(char));

    // Allocate memory for COLLEGE structure and its members
    student_ptr->college_ptr = (struct COLLEGE *)malloc(sizeof(struct COLLEGE));
    student_ptr->college_ptr->college_name = (char *)malloc(50 * sizeof(char));
    student_ptr->college_ptr->university_name = (char *)malloc(50 * sizeof(char));

    // Input from user
    printf("Enter day of birth: ");
    scanf("%d", &(student_ptr->dob_ptr->day));

    printf("Enter month of birth: ");
    scanf("%d", student_ptr->dob_ptr->month);

    printf("Enter year of birth: ");
    scanf("%d", &(student_ptr->dob_ptr->year));

    printf("Enter registration number: ");
    scanf("%d", &(student_ptr->info_ptr->reg_no));

    printf("Enter name: ");
    scanf("%s", student_ptr->info_ptr->name);

    printf("Enter address: ");
    scanf("%s", student_ptr->info_ptr->address);

    printf("Enter college name: ");
    scanf("%s", student_ptr->college_ptr->college_name);

    printf("Enter university name: ");
    scanf("%s", student_ptr->college_ptr->university_name);

    // Display the entered values
    printf("\nStudent Details:\n");
    printf("Date of Birth: %d-%d-%d\n", student_ptr->dob_ptr->day, *(student_ptr->dob_ptr->month), student_ptr->dob_ptr->year);
    printf("Registration Number: %d\n", student_ptr->info_ptr->reg_no);
    printf("Name: %s\n", student_ptr->info_ptr->name);
    printf("Address: %s\n", student_ptr->info_ptr->address);
    printf("College: %s\n", student_ptr->college_ptr->college_name);
    printf("University: %s\n", student_ptr->college_ptr->university_name);

    // Free allocated memory
    free(student_ptr->college_ptr->university_name);
    free(student_ptr->college_ptr->college_name);
    free(student_ptr->college_ptr);
    free(student_ptr->info_ptr->address);
    free(student_ptr->info_ptr->name);
    free(student_ptr->info_ptr);
    free(student_ptr->dob_ptr->month);
    free(student_ptr->dob_ptr);
    free(student_ptr);

    return 0;
}
