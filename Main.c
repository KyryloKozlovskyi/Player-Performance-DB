#include "Player.h"
#include "Login.h"
#include "Menu.h"
#include<stdio.h>
#include<stdlib.h>


void main()
{
	int isAuth = 0; // 1 if the user is authenticated, 0 otherwise

	isAuth = processLogin(); // Authenticate the user

	// Debugging purposes
    if (isAuth == 1) {
        printf("Login successful!\n");
    }
    else {
        printf("Invalid username or password.\n");
        exit(0);
    }
}