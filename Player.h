#ifndef PLAYER_H
#define PLAYER_H

#include <stdio.h>

// Structure to represent player details
typedef struct playerDetails {
	int irfuNumber;  // Must be unique
	char firstName[99];
	char secondName[99];
	int age;
	float height;
	float weight;
	char club[99];
	char email[99];      // Must contain an @, a full stop and a .com
	int playerPosition;  // list of options (1 - 7) format
	int missedTackles;   // list of options (1 - 4) format
	int playerMetres;    // list of options (1 - 4) format
	struct playerDetails* next;
} playerDetails;

// Function prototypes
void readPlayerFile(playerDetails** top);
void addElementAtStartP(playerDetails** top, playerDetails details);
void addElementAtEndP(playerDetails* top, playerDetails details);
void displayAllPlayers(playerDetails* top);
void addPlayer(playerDetails** top);
void displayPlayer(playerDetails* top);
playerDetails* searchByName(playerDetails* top);
playerDetails* searchByIRFU(playerDetails* top);
int isIRFUnumberUnique(playerDetails* top, int irfuNumber);
void updatePlayer(playerDetails* top);
void deletePlayer(playerDetails** top);
int isValidEmail(char email[99]);
void generateStatistics(playerDetails* top, int report);
void updatePlayerFile(playerDetails* top);
void displayPlayerPositions();
void displayPlayerMetres();
void displayMissedTackles();
// Unimplemented functions
// void listPlayersByHeight(playerDetails* top);
// void swapPlayers(playerDetails* a, playerDetails* b);
// void bubbleSort(playerDetails* top);

#endif  // PLAYER_H