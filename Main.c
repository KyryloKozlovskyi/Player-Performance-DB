#include <stdio.h>
#include <stdlib.h>

#include "Login.h"
#include "Menu.h"
#include "Player.h"

void main() {
    int isAuth = 0;  // 1 if the user is authenticated, 0 otherwise
    // Runner
    /*
    // Welcome message
    printf("********** Rugby Performance Metric **********\n");
    printf("Please enter your credentials to log in\n");

        isAuth = processLogin(); // Authenticate the user

        // Debugging purposes
    if (isAuth == 1) {
        printf("Login successful!\n");
    }
    else {
        printf("Invalid username or password.\n");
        exit(0);
    }
    */
    //processMenu();  // Display the menu
    readPlayerFile();
}