#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Login.h"

// Read the login file and store the credentials in a linked list. Prompt the
// user to enter their credentials. Compare the user's input with the stored
// credentials. Return 1 if the user is authenticated, 0 otherwise.
int processLogin() {
    int flag = 0;                  // 1 if the user is authenticated, 0 otherwise
    FILE* fp;                      // File pointer
    loginDetails* headPtr = NULL;  // Head pointer of the linked list
    // loginDetails* temp; // Debugging purposes
    fp = fopen("Login.txt", "r");
    if (NULL == fp) {
        printf("File can't be opened!\n");
        return;
    }
    else {
        while (!feof(fp)) {
            addElementAtStart(&headPtr, fp);
        }
    }
    fclose(fp);  // Close the file

    // Debugging purposes
    /*
    temp = headPtr;
    while (temp != NULL)
    {
        printf("Username: %s\nPassword: %s\n\n", temp->username, temp->password);
        temp = temp->next;
    }
    */
    flag = getUserCredentials(headPtr);  // Store the return value
    free(headPtr);  // Free the memory allocated for the linked list

    return flag;
}

// Add an element at the start of the linked list
void addElementAtStart(loginDetails** top, FILE* fp) {
    loginDetails* temp;  // Temporary node

    temp = (loginDetails*)malloc(
        sizeof(loginDetails));  // Allocate memory for the new node

    fscanf(fp, "%s %s", temp->username,
        temp->password);  // Read the username and password from the file
    temp->next = *top;       // Point the new node to the current head
    *top = temp;             // Make the new node the head
}

// Compare the user's input with the stored credentials
int compareCredentials(char username[99], char password[7], loginDetails* top) {
    int flag = 0;  // 1 if the user is authenticated, 0 otherwise
    loginDetails* temp = top;
    // printf("Username: %s\nPassword: %s\n", username, password); // Debugging
    // purposes
    while (temp != NULL) {
        if (strcmp(temp->username, username) == 0 &&
            strcmp(temp->password, password) == 0) {
            flag = 1;
            break;
        }
        temp = temp->next;
    }
    return flag;
}

// Get the user's input
int getUserCredentials(loginDetails* top) {
    int flag = 0;       // 1 if the user is authenticated, 0 otherwise
    char username[99];  // 98 characters for the username and 1 for the null
    // terminator
    char password[7];  // 6 characters for the password and 1 for the null
    // terminator

    printf("Enter your username: ");
    fgets(username, sizeof(username), stdin);
    // Remove the trailing newline character
    username[strcspn(username, "\n")] = '\0';

    printf("Enter your password: ");
    fgets(password, sizeof(password), stdin);
    // Remove the trailing newline character
    password[strcspn(password, "\n")] = '\0';

    flag = compareCredentials(username, password, top);  // Store the return value

    // Debugging purposes
    /*
    if (isAuthenticated == 1) {
        printf("Login successful!\n");
    }
    else {
        printf("Invalid username or password.\n");
    }
    */
    return flag;
}
