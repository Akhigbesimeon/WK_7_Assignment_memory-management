#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LEN 50 
#define INITIAL_STUDENTS 10
#define REDUCED_STUDENTS 6

// Function for reading email addresses
void readEmails(char **emails, int n) {
    for (int i = 0; i < n; i++) {
        emails[i] = (char *)malloc(MAX_EMAIL_LEN * sizeof(char));
        if (emails[i] == NULL) {
            printf("Memory allocation failed for student %d\n", i + 1);
            exit(1);
        }
        printf("Enter email for student %d: ", i + 1);
        fgets(emails[i], MAX_EMAIL_LEN, stdin);
        size_t len = strlen(emails[i]);
        if (len > 0 && emails[i][len - 1] == '\n') {
            emails[i][len - 1] = '\0';
        }
    }
}

// Function to display email addresses
void displayEmails(char **emails, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d. %s\n", i + 1, emails[i]);
    }
}

// Function to free memory
void freeEmails(char **emails, int n) {
    for (int i = 0; i < n; i++) {
        free(emails[i]);
    }
    free(emails);
}

int main() {
    char **emails = (char **)malloc(INITIAL_STUDENTS * sizeof(char *));
    if (emails == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Read and display emails
    readEmails(emails, INITIAL_STUDENTS);
    displayEmails(emails, INITIAL_STUDENTS);

    // Retain 6 student emails
    for (int i = REDUCED_STUDENTS; i < INITIAL_STUDENTS; i++) {
        free(emails[i]);
    }

    // Reallocate memory for 6 students
    char **resizedEmails = (char **)realloc(emails, REDUCED_STUDENTS * sizeof(char *));
    if (resizedEmails == NULL) {
        printf("Memory reallocation failed\n");
        freeEmails(emails, REDUCED_STUDENTS);
        return 1;
    }
    emails = resizedEmails;

    // Displays updated email list
    printf("\nFirst 6 student email addresses:\n");
    displayEmails(emails, REDUCED_STUDENTS);

    // Frees all allocated memory
    freeEmails(emails, REDUCED_STUDENTS);

    return 0;
}

