#include <conio.h>
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
    int flag = 0;  // 1 if the user is authenticated, 0 otherwise
    char username[99];
    char password[7];
    char ch;    // Character read from the console
    int i = 0;  // Index for password buffer

    // Get the username from the user
    printf("Username: ");
    fgets(username, sizeof(username), stdin);
    // Remove the trailing newline character
    username[strcspn(username, "\n")] = '\0';

    // Get the password from the user and mask it with *
    printf("Password: ");
    while ((ch = getch()) != '\r' && ch != '\n') {
        if (ch == '\b') {
            if (i > 0) {
                password[--i] =
                    '\0';         // Remove the last character from the password buffer
                printf("\b \b");  // Erase the last character from the console
            }
        }
        else if (isprint(ch) && i < 6) {
            password[i++] = ch;  // Add the character to the password buffer
            printf("*");         // Print * to the console
        }
    }
    password[i] = '\0'; // Null to end the string (buffer)
    printf("\n");

    flag = compareCredentials(username, password, top);  // Store the return value

    return flag;
}
