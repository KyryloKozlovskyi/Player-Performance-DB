#ifndef PLAYER
#define PLAYER

// Structure to represent player details
typedef struct node {
	int irfuNumber;  // must be unique
	char firstName[99];
	char secondName[99];
	int age;
	float height;
	float weight;
	char club[99];
	char email[99];      // must contain an @, a full stop and a .com
	int playerPosition;  // list of options (1 - option) format
	int missedTackles;   // list of options (1 - option) format
	int playerMetres;    // list of options (1 - option) format
	struct node* next;
} playerDetails;

void addPlayer(playerDetails* top);
void displayAll(playerDetails* top);
void displayPlayer(playerDetails* top);
void updatePlayer(playerDetails* top);
void deletePlayer(playerDetails* top);
void generateStatistics(playerDetails* top);
void writeReport(playerDetails* top);
void listPlayersCategory(playerDetails* top);

#endif #pragma once