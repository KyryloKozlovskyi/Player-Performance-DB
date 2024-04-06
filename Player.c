#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Player.h"

// Read the player file and store the details in a linked list
playerDetails* headPtr = NULL;
void readPlayerFile() {
    FILE* fp;  // File pointer

    fp = fopen("Rugby.txt", "r");
    if (fp == NULL) {
        printf("File can't be opened!\n");
        return;
    }
    else {
        while (!feof(fp)) {
            playerDetails temp;
            fscanf(fp, "%d %s %s %d %f %f %s %s %d %d %d", &temp.irfuNumber,
                temp.firstName, temp.secondName, &temp.age, &temp.height,
                &temp.weight, temp.club, temp.email, &temp.playerPosition,
                &temp.missedTackles, &temp.playerMetres);
            // addElementAtStartP(&headPtr, temp);

            if (headPtr == NULL) {
                addElementAtStartP(&headPtr, temp);
            }
            else {
                addElementAtEndP(headPtr, temp);
            }
        }
    }
    fclose(fp);  // Close the file

    printPlayerDetails(headPtr);
    addPlayer(headPtr);
    printf("***************************************");
    printPlayerDetails(headPtr);
}

void addElementAtStartP(playerDetails** top, playerDetails details) {
    playerDetails* temp;

    temp = (playerDetails*)malloc(sizeof(playerDetails));

    temp = &details;

    temp->next = *top;
    *top = temp;
}

void addElementAtEndP(playerDetails* top, playerDetails details) {
    playerDetails* newNode = (playerDetails*)malloc(sizeof(playerDetails));
    playerDetails* temp = top;

    *newNode = details;

    newNode->next =
        NULL;  // Make sure the new node points to NULL as it's the last node

    // Traverse the list to find the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }
    // Connect the last node to the new node
    temp->next = newNode;
}

// Print all player details in the linked list
void printPlayerDetails(playerDetails* top) {
    playerDetails* temp = top;

    // Iterate through the linked list
    while (temp != NULL) {
        printf("IRFU Number: %d\n", temp->irfuNumber);
        printf("First Name: %s\n", temp->firstName);
        printf("Second Name: %s\n", temp->secondName);
        printf("Age: %d\n", temp->age);
        printf("Height: %.2f\n", temp->height);
        printf("Weight: %.2f\n", temp->weight);
        printf("Club: %s\n", temp->club);
        printf("Email: %s\n", temp->email);
        printf("Player Position: %d\n", temp->playerPosition);
        printf("Missed Tackles: %d\n", temp->missedTackles);
        printf("Player Metres: %d\n", temp->playerMetres);
        printf("\n");

        temp = temp->next;  // Move to the next node
    }
}

void addPlayer(playerDetails* top) {
	playerDetails temp;

	printf("Enter IRFU Number: ");
	scanf("%d", &temp.irfuNumber);
	printf("Enter First Name: ");
	scanf("%s", temp.firstName);
	printf("Enter Second Name: ");
	scanf("%s", temp.secondName);
	printf("Enter Age: ");
	scanf("%d", &temp.age);
	printf("Enter Height: ");
	scanf("%f", &temp.height);
	printf("Enter Weight: ");
	scanf("%f", &temp.weight);
	printf("Enter Club: ");
	scanf("%s", temp.club);
	printf("Enter Email: ");
	scanf("%s", temp.email);
	printf("Enter Player Position: ");
	scanf("%d", &temp.playerPosition);
	printf("Enter Missed Tackles: ");
	scanf("%d", &temp.missedTackles);
	printf("Enter Player Metres: ");
	scanf("%d", &temp.playerMetres);

	addElementAtEndP(top, temp);
}