#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "Login.h"
#include "Menu.h"
#include "Player.h"

void main() {
    int isAuth = 0;                 // 1 if the user is authenticated, 0 otherwise
    playerDetails* headPtr = NULL;  // Pointer to the head of the linked list

    // Welcome message

    printf("********** Rugby Performance Metric **********\n");
    printf("Please enter your credentials to log in\n");

    isAuth = processLogin();  // Authenticate the user

    // Debugging purposes
    if (isAuth == 1) {
        system("cls");
        printf("Login successful!\n");
        Sleep(500);
    }
    else {
        system("cls");
        printf("Invalid username or password.\n");
        Sleep(500);
        exit(0);
    }

    readPlayerFile(&headPtr);
    processMenu(headPtr);  // Display the menu

    return 0;
}