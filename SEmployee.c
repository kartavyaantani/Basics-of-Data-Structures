#include <stdio.h>
#include <stdlib.h>

// Define the structure for Date of Birth
struct Date {
    int day;
    int month;
    int year;
};

// Define the structure for Address
struct Address {
    int houseNumber;
    int zipCode;
    char state[50];
};

// Define the structure for Employee
struct Employee {
    char name[50];
    struct Date dob;
    struct Address address;
};

int main() {
    int N;

    printf("Enter the number of employees: ");
    scanf("%d", &N);

    // Dynamically allocate memory for an array of Employee structures
    struct Employee *employees = (struct Employee *)malloc(N * sizeof(struct Employee));

    // Input data for each employee
    for (int i = 0; i < N; i++) {
        printf("Enter details for Employee %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", employees[i].name);
        printf("Date of Birth (day month year): ");
        scanf("%d %d %d", &employees[i].dob.day, &employees[i].dob.month, &employees[i].dob.year);
        printf("Address (house number zip code state): ");
        scanf("%d %d %s", &employees[i].address.houseNumber, &employees[i].address.zipCode, employees[i].address.state);
    }

    // Display data for each employee
    printf("\nEmployee Details:\n");
    for (int i = 0; i < N; i++) {
        printf("Employee %d:\n", i + 1);
        printf("Name: %s\n", employees[i].name);
        printf("Date of Birth: %d-%d-%d\n", employees[i].dob.day, employees[i].dob.month, employees[i].dob.year);
        printf("Address: %d, %d, %s\n", employees[i].address.houseNumber, employees[i].address.zipCode, employees[i].address.state);
        printf("\n");
    }

    // Free the dynamically allocated memory
    free(employees);

    return 0;
}

