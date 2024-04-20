#ifndef LOGIN_H
#define LOGIN_H

#include <stdio.h>

// Structure to represent login credentials
typedef struct loginDetails {
	char username[99];
	char password[7];
	struct loginDetails* next;
} loginDetails;

// Function prototypes
int processLogin();
void addElementAtStart(loginDetails** top, FILE* fp);
int compareCredentials(char username[99], char password[7], loginDetails* top);
int getUserCredentials(loginDetails* top);
#endif  // LOGIN_H
