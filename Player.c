#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Player.h"

// Read the player file and store the details in a linked list
playerDetails* headPtr = NULL;
void readPlayerFile() {
    FILE* fp;  // File pointer
    playerDetails* headPtr = NULL;

    fp = fopen("Rugby.txt", "r");
    if (fp == NULL) {
        printf("File can't be opened!\n");
        return;
    }
    else {
        while (!feof(fp)) {
            addElementAtStartP(&headPtr, fp);
            /*
            if (headPtr == NULL) {
                addElementAtStartP(&headPtr, fp);
            }
            else {
                addElementAtEndP(headPtr, fp);
            }
            */
        }
    }
    fclose(fp);  // Close the file

    printPlayerDetails(headPtr); 
}

void addElementAtStartP(playerDetails** top, FILE* fp) {
    playerDetails* temp;

    temp = (playerDetails*)malloc(sizeof(playerDetails));
    fscanf(fp, "%d %s %s %d %f %f %s %s %d %d %d", &temp->irfuNumber,
        temp->firstName, temp->secondName, &temp->age, &temp->height,
        &temp->weight, temp->club, temp->email, &temp->playerPosition,
        &temp->missedTackles, &temp->playerMetres);

    temp->next = *top;
    *top = temp;
}

void addElementAtEndP(playerDetails* top, FILE* fp) {
    playerDetails* newNode;
    playerDetails* temp;
    newNode = (playerDetails*)malloc(sizeof(playerDetails));
    temp = top;

    fscanf(fp, "%d %s %s %d %f %f %s %s %d %d %d", &temp->irfuNumber,
        temp->firstName, temp->secondName, &temp->age, &temp->height,
        &temp->weight, temp->club, temp->email, &temp->playerPosition,
        &temp->missedTackles, &temp->playerMetres);


    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = NULL;
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