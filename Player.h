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


void readPlayerFile();
void addElementAtStartP(playerDetails** top, playerDetails details);
void addElementAtEndP(playerDetails* top, playerDetails details);
void printPlayerDetails(playerDetails* top);
void addPlayer(playerDetails* top);
/*
void addPlayer(playerDetails* top);
void displayAll(playerDetails* top);
void displayPlayer(playerDetails* top);
void updatePlayer(playerDetails* top);
void deletePlayer(playerDetails* top);
void generateStatistics(playerDetails* top);
void writeReport(playerDetails* top);
void listPlayersCategory(playerDetails* top);
*/

#endif  // PLAYER_H