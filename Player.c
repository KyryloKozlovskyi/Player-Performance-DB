#define _CRT_SECURE_NO_WARNINGS

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "Player.h"

void readPlayerFile(playerDetails** top) {
    printf("Initializing DB...\n");
    Sleep(500);
    system("cls");
    FILE* fp;  // File pointer

    // Open the file
    fp = fopen("Rugby.txt", "r");
    if (fp == NULL) {
        printf("File can't be opened!\n");
        return;
    }
    else {
        // Read the file and store the player details in the linked list
        while (1) {
            playerDetails temp;
            int result =
                fscanf(fp, "%d %s %s %d %f %f %s %s %d %d %d", &temp.irfuNumber,
                    temp.firstName, temp.secondName, &temp.age, &temp.height,
                    &temp.weight, temp.club, temp.email, &temp.playerPosition,
                    &temp.missedTackles, &temp.playerMetres);

            // Check if reading was successful
            if (result == EOF) {
                break;  // End of file reached
            }

            // Add the player to the linked list
            if (*top == NULL) {
                addElementAtStartP(
                    top,
                    temp);  // If the linked list is empty, add the player at the start
            }
            else {
                addElementAtEndP(*top, temp);  // If the linked list is not empty, add
                // the player at the end
            }
        }
    }
    fclose(fp);  // Close the file
}

// Add a new element at the start of the linked list
void addElementAtStartP(playerDetails** top, playerDetails details) {
    playerDetails* temp;

    temp = (playerDetails*)malloc(sizeof(playerDetails));
    *temp = details;

    temp->next = *top;
    *top = temp;
}

// Add a new element at the end of the linked list
void addElementAtEndP(playerDetails* top, playerDetails details) {
    playerDetails* newNode = (playerDetails*)malloc(sizeof(playerDetails));
    playerDetails* temp = top;

    *newNode = details;

    newNode->next = NULL;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Search for a player by their full names
playerDetails* searchByName(playerDetails* top) {
    char firstName[99];
    char secondName[99];
    playerDetails* temp = top;
    int found = 0;

    // Take user input
    printf("Enter First Name: ");
    if (scanf("%s", firstName) != 1) {
        printf("Invalid input! Please enter a valid First Name.\n");
        while (getchar() != '\n')
            ;  // Clear the input buffer
        return NULL;
    }

    printf("Enter Second Name: ");
    if (scanf("%s", secondName) != 1) {
        printf("Invalid input! Please enter a valid Second Name.\n");
        while (getchar() != '\n')
            ;  // Clear the input buffer
        return NULL;
    }

    // Iterate over the linked list and search for the player
    while (temp != NULL) {
        if (strcmp(firstName, temp->firstName) == 0 &&
            strcmp(secondName, temp->secondName) == 0) {
            system("cls");
            printf("**********************************************\n");
            displayPlayerPositions();
            displayMissedTackles();
            displayPlayerMetres();
            printf("**********************************************\n");
            printf("Player Details:\n");
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
            found = 1;
            return temp;
        }
        temp = temp->next;
    }

    // If the player is not found
    if (found == 0) {
        printf("%s %s is not in the DB\n", firstName, secondName);
        return NULL;
    }
}

// Search for a player by their IRFU number
playerDetails* searchByIRFU(playerDetails* top) {
    int irfuNumber;
    playerDetails* temp = top;
    int found = 0;

    // Take user input
    printf("Enter IRFU Number: ");
    if (scanf("%d", &irfuNumber) != 1) {
        printf("Invalid input! Please enter a valid IRFU Number.\n");
        while (getchar() != '\n')
            ;  // Clear the input buffer
        return NULL;
    }

    // Iterate over the linked list and search for the player
    while (temp != NULL) {
        if (irfuNumber == temp->irfuNumber) {
            system("cls");
            printf("**********************************************\n");
            displayPlayerPositions();
            displayMissedTackles();
            displayPlayerMetres();
            printf("**********************************************\n");
            printf("Player Details:\n");
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
            found = 1;
            return temp;
        }
        temp = temp->next;
    }

    // If the player is not found
    if (found == 0) {
        printf("IRFU Number %d is not in the DB\n", irfuNumber);
        return NULL;
    }
}

// Check if the IRFU number is unique
int isIRFUnumberUnique(playerDetails* top, int irfuNumber) {
    playerDetails* temp = top;

    // Iterate over the linked list and check if the IRFU number already exists
    while (temp != NULL) {
        if (temp->irfuNumber == irfuNumber) {
            // IRFU number already exists
            return 0;
        }
        temp = temp->next;
    }

    // IRFU number is unique
    return 1;
}

// Validate the email address
int isValidEmail(char email[99]) {
    int atCount = 0;
    int dotCount = 0;

    // Check for '@' and '.'
    for (int i = 0; i < strlen(email); i++) {
        if (email[i] == '@') {
            atCount++;
        }
        if (email[i] == '.') {
            dotCount++;
        }
    }

    // Check if there is exactly one '@' and one or more '.'
    if (atCount == 1 && dotCount > 0 && strstr(email, ".com") != NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

// Add a new player to the linked list
void addPlayer(playerDetails** top) {
    system("cls");
    playerDetails temp;  // Temporary variable to store the player details

    // Get user input and validate it
    printf("Enter IRFU Number: ");
    if (scanf("%d", &temp.irfuNumber) != 1) {
        printf("Invalid input! Please enter a valid IRFU Number.\n");
        while (getchar() != '\n')
            ;  // Clear the input buffer
        return;
    }

    // Check if the IRFU number is unique
    if (!isIRFUnumberUnique(*top, temp.irfuNumber)) {
        printf(
            "IRFU Number is not unique! Please enter a different IRFU Number.\n");
        return;
    }

    printf("Enter First Name: ");
    if (scanf("%s", temp.firstName) != 1) {
        printf("Invalid input! Please enter a valid First Name.\n");
        while (getchar() != '\n')
            ;  // Clear the input buffer
        return;
    }

    printf("Enter Second Name: ");
    if (scanf("%s", temp.secondName) != 1) {
        printf("Invalid input! Please enter a valid Second Name.\n");
        while (getchar() != '\n')
            ;  // Clear the input buffer
        return;
    }

    printf("Enter Age: ");
    if (scanf("%d", &temp.age) != 1) {
        printf("Invalid input! Please enter a valid Age.\n");
        while (getchar() != '\n')
            ;  // Clear the input buffer
        return;
    }

    printf("Enter Height: ");
    if (scanf("%f", &temp.height) != 1) {
        printf("Invalid input! Please enter a valid Height.\n");
        while (getchar() != '\n')
            ;  // Clear the input buffer
        return;
    }

    printf("Enter Weight: ");
    if (scanf("%f", &temp.weight) != 1) {
        printf("Invalid input! Please enter a valid Weight.\n");
        while (getchar() != '\n')
            ;  // Clear the input buffer
        return;
    }

    printf("Enter Club: ");
    if (scanf("%s", temp.club) != 1) {
        printf("Invalid input! Please enter a valid Club.\n");
        while (getchar() != '\n')
            ;  // Clear the input buffer
        return;
    }

    printf("Enter Email: ");
    if (scanf("%s", temp.email) != 1 || isValidEmail(temp.email) != 1) {
        printf("Invalid input! Please enter a valid Email.\n");
        while (getchar() != '\n')
            ;  // Clear the input buffer
        return;
    }

    do {
        displayPlayerPositions();
        printf("Enter Player Position (1-7): ");
        if (scanf("%d", &temp.playerPosition) != 1 || temp.playerPosition < 1 ||
            temp.playerPosition > 7) {
            printf("Invalid input! Please enter a valid Player Position (1-7).\n");
            while (getchar() != '\n')
                ;  // Clear the input buffer
        }
    } while (temp.playerPosition < 1 || temp.playerPosition > 7);

    do {
        displayMissedTackles();
        printf("Enter Missed Tackles (1-4): ");
        if (scanf("%d", &temp.missedTackles) != 1 || temp.missedTackles < 1 ||
            temp.missedTackles > 4) {
            printf("Invalid input! Please enter valid Missed Tackles (1-4).\n");
            while (getchar() != '\n')
                ;  // Clear the input buffer
        }
    } while (temp.missedTackles < 1 || temp.missedTackles > 4);

    do {
        displayPlayerMetres();
        printf("Enter Player Metres (1-4): ");
        if (scanf("%d", &temp.playerMetres) != 1 || temp.playerMetres < 1 ||
            temp.playerMetres > 4) {
            printf("Invalid input! Please enter valid Player Metres (1-4).\n");
            while (getchar() != '\n')
                ;  // Clear the input buffer
        }
    } while (temp.playerMetres < 1 || temp.playerMetres > 4);

    // Add the player to the linked list check if the linked list is empty
    if (*top == NULL) {
        addElementAtStartP(top, temp);
    }
    else {
        addElementAtEndP(*top, temp);
    }
}

// Print all player details from the linked list
void displayAllPlayers(playerDetails* top) {
    system("cls");
    playerDetails* temp = top;
    printf("**********************************************\n");
    displayPlayerPositions();
    displayMissedTackles();
    displayPlayerMetres();
    printf("**********************************************\n");
    printf("************* All Player Details *************\n");
    // Iterate over the linked list and print the details of each player
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
    printf("**********************************************\n");
}

// Display player details based on the search criteria
void displayPlayer(playerDetails* top) {
    int choice;

    // Ask the user for the search criteria
    printf("Enter \"1\" to search by name or \"2\" to search by IRFU number: ");
    if (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2)) {
        printf("Invalid choice!\n");
        while (getchar() != '\n')
            ;  // Clear the input buffer
        return;
    }

    // Menu to search by name or IRFU number
    switch (choice) {
    case 1:
        searchByName(top);
        break;
    case 2:
        searchByIRFU(top);
        break;
    default:
        printf("Invalid choice!\n");
        break;
    }
}

// Update player details
void updatePlayer(playerDetails* top) {
    playerDetails* playerToUpdate;

    int choice;

    // Ask the user for the search criteria
    printf("Enter \"1\" to search by name or \"2\" to search by IRFU number: ");
    if (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2)) {
        printf("Invalid choice!\n");
        while (getchar() != '\n')
            ;  // Clear the input buffer
        return;
    }

    // Menu to search by name or IRFU number
    switch (choice) {
    case 1:
        playerToUpdate = searchByName(top);
        break;
    case 2:
        playerToUpdate = searchByIRFU(top);
        break;
    default:
        printf("Invalid choice!\n");
        break;
    }

    // Get user input and validate it
    printf("Enter First Name: ");
    if (scanf("%s", playerToUpdate->firstName) != 1) {
        printf("Invalid input! Please enter a valid First Name.\n");
        while (getchar() != '\n')
            ;  // Clear the input buffer
        return;
    }

    printf("Enter Second Name: ");
    if (scanf("%s", playerToUpdate->secondName) != 1) {
        printf("Invalid input! Please enter a valid Second Name.\n");
        while (getchar() != '\n')
            ;  // Clear the input buffer
        return;
    }

    printf("Enter Age: ");
    if (scanf("%d", &playerToUpdate->age) != 1) {
        printf("Invalid input! Please enter a valid Age.\n");
        while (getchar() != '\n')
            ;  // Clear the input buffer
        return;
    }

    printf("Enter Height: ");
    if (scanf("%f", &playerToUpdate->height) != 1) {
        printf("Invalid input! Please enter a valid Height.\n");
        while (getchar() != '\n')
            ;  // Clear the input buffer
        return;
    }

    printf("Enter Weight: ");
    if (scanf("%f", &playerToUpdate->weight) != 1) {
        printf("Invalid input! Please enter a valid Weight.\n");
        while (getchar() != '\n')
            ;  // Clear the input buffer
        return;
    }

    printf("Enter Club: ");
    if (scanf("%s", playerToUpdate->club) != 1) {
        printf("Invalid input! Please enter a valid Club.\n");
        while (getchar() != '\n')
            ;  // Clear the input buffer
        return;
    }

    printf("Enter Email: ");
    if (scanf("%s", playerToUpdate->email) != 1) {
        printf("Invalid input! Please enter a valid Email.\n");
        while (getchar() != '\n')
            ;  // Clear the input buffer
        return;
    }

    printf("Enter Player Position: ");
    if (scanf("%d", &playerToUpdate->playerPosition) != 1) {
        printf("Invalid input! Please enter a valid Player Position.\n");
        while (getchar() != '\n')
            ;  // Clear the input buffer
        return;
    }

    printf("Enter Missed Tackles: ");
    if (scanf("%d", &playerToUpdate->missedTackles) != 1) {
        printf("Invalid input! Please enter valid Missed Tackles.\n");
        while (getchar() != '\n')
            ;  // Clear the input buffer
        return;
    }

    printf("Enter Player Metres: ");
    if (scanf("%d", &playerToUpdate->playerMetres) != 1) {
        printf("Invalid input! Please enter valid Player Metres.\n");
        while (getchar() != '\n')
            ;  // Clear the input buffer
        return;
    }
}

// Delete a player from the linked list
void deletePlayer(playerDetails** top) {
    playerDetails* temp = *top;
    playerDetails* prev = NULL;
    playerDetails* playerToDelete;
    int choice;

    // Search for the player to delete
    playerToDelete = searchByIRFU(*top);

    if (playerToDelete != NULL) {
        // If the player to delete is the first node
        if (temp == playerToDelete) {
            *top = temp->next;
            free(temp);
            printf("Player deleted successfully!\n");
            return;
        }

        // Traverse the list to find the player and keep track of the previous node
        while (temp != NULL && temp != playerToDelete) {
            prev = temp;
            temp = temp->next;
        }

        // If the player is found in the list
        if (temp == playerToDelete) {
            prev->next = temp->next;
            free(temp);
            printf("Player deleted successfully!\n");
        }
    }
}

// Generates statistics based on a range of player weights
void generateStatistics(playerDetails* top, int report) {
    FILE* file;
    float minWeight, maxWeight;
    int totalPlayers = 0;
    int noMissedTackles = 0, lessThan3MissedTackles = 0,
        lessThan5MissedTackles = 0, moreThan5MissedTackles = 0;
    int noPlayerMetres = 0, lessThan10PlayerMetres = 0,
        lessThan20PlayerMetres = 0, moreThan20PlayerMetres = 0;
    float totalWeightInRange = 0;

    printf("Enter the weight range (min): ");
    if (scanf("%f", &minWeight) != 1) {
        printf("Invalid input!\n");
        while (getchar() != '\n')
            ;  // Clear the input buffer
        return;
    }

    printf("Enter the weight range (max): ");
    if (scanf("%f", &maxWeight) != 1) {
        printf("Invalid input!\n");
        while (getchar() != '\n')
            ;  // Clear the input buffer
        return;
    }
    // Calculate total number of players and total weight within the range
    playerDetails* temp = top;
    while (temp != NULL) {
        if (temp->weight >= minWeight && temp->weight <= maxWeight) {
            totalPlayers++;
            totalWeightInRange += temp->weight;

            // Tackle statistics
            switch (temp->missedTackles) {
            case 1:
                noMissedTackles++;
                break;
            case 2:
                lessThan3MissedTackles++;
                break;
            case 3:
                lessThan5MissedTackles++;
                break;
            case 4:
                moreThan5MissedTackles++;
                break;
            }

            // Player metres statistics
            switch (temp->playerMetres) {
            case 1:
                noPlayerMetres++;
                break;
            case 2:
                lessThan10PlayerMetres++;
                break;
            case 3:
                lessThan20PlayerMetres++;
                break;
            case 4:
                moreThan20PlayerMetres++;
                break;
            }
        }

        temp = temp->next;
    }

    // Calculate percentages
    float percentNoMissedTackles = ((float)noMissedTackles / totalPlayers) * 100;
    float percentLessThan3MissedTackles =
        ((float)lessThan3MissedTackles / totalPlayers) * 100;
    float percentLessThan5MissedTackles =
        ((float)lessThan5MissedTackles / totalPlayers) * 100;
    float percentMoreThan5MissedTackles =
        ((float)moreThan5MissedTackles / totalPlayers) * 100;

    float percentNoPlayerMetres = ((float)noPlayerMetres / totalPlayers) * 100;
    float percentLessThan10PlayerMetres =
        ((float)lessThan10PlayerMetres / totalPlayers) * 100;
    float percentLessThan20PlayerMetres =
        ((float)lessThan20PlayerMetres / totalPlayers) * 100;
    float percentMoreThan20PlayerMetres =
        ((float)moreThan20PlayerMetres / totalPlayers) * 100;
    switch (report) {
    case 0:  // Print statistics
        // Print statistics
        printf("Total number of players: %d", totalPlayers);
        printf("%% of players who miss no tackles: %.2f%%\n",
            percentNoMissedTackles);
        printf("%% of players who miss less than 3 tackles per match: %.2f%%\n",
            percentLessThan3MissedTackles);
        printf("%% of players who miss less than 5 tackles per match: %.2f%%\n",
            percentLessThan5MissedTackles);
        printf("%% of players who miss more than 5 tackles per match: %.2f%%\n",
            percentMoreThan5MissedTackles);
        printf("%% of players who make no metres in a game: %.2f%%\n",
            percentNoPlayerMetres);
        printf("%% of players who make less than 10 metres in a game: %.2f%%\n",
            percentLessThan10PlayerMetres);
        printf("%% of players who make less than 20 metres in a game: %.2f%%\n",
            percentLessThan20PlayerMetres);
        printf("%% of players who make more than 20 metres in a game: %.2f%%\n",
            percentMoreThan20PlayerMetres);
        break;
    case 1:  // Write report to file
        system("cls");
        printf("Writing report to a file...\n");
        Sleep(500);

        file = fopen("report.txt", "w");
        if (file == NULL) {
            printf("Error opening file!\n");
            return;
        }
        // Write statistics to the report file
        fprintf(file, "************* Player statistics *************\n");
        fprintf(file, "Players in the range %.2f to %.2f\n", minWeight,
            maxWeight);
        fprintf(file, "Total number of players: %d\n", totalPlayers);
        fprintf(file, "%% of players who miss no tackles: %.2f%%\n",
            percentNoMissedTackles);
        fprintf(file,
            "%% of players who miss less than 3 tackles per match: %.2f%%\n",
            percentLessThan3MissedTackles);
        fprintf(file,
            "%% of players who miss less than 5 tackles per match: %.2f%%\n",
            percentLessThan5MissedTackles);
        fprintf(file,
            "%% of players who miss more than 5 tackles per match: %.2f%%\n",
            percentMoreThan5MissedTackles);
        fprintf(file, "%% of players who make no metres in a game: %.2f%%\n",
            percentNoPlayerMetres);
        fprintf(file,
            "%% of players who make less than 10 metres in a game: %.2f%%\n",
            percentLessThan10PlayerMetres);
        fprintf(file,
            "%% of players who make less than 20 metres in a game: %.2f%%\n",
            percentLessThan20PlayerMetres);
        fprintf(file,
            "%% of players who make more than 20 metres in a game: %.2f%%\n",
            percentMoreThan20PlayerMetres);
        fprintf(file, "**********************************************\n");
        fclose(file);
        break;
    default:
        printf("Invalid Input!");
        break;
    }
}

// Write all player details to a report file
void writePlayerToFile(playerDetails* top) {
    FILE* file;
    playerDetails* temp = top;

    file = fopen("report.txt", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fprintf(file, "************* All Player Details *************\n");
    while (temp != NULL) {
        fprintf(file, "IRFU Number: %d\n", temp->irfuNumber);
        fprintf(file, "First Name: %s\n", temp->firstName);
        fprintf(file, "Second Name: %s\n", temp->secondName);
        fprintf(file, "Age: %d\n", temp->age);
        fprintf(file, "Height: %.2f\n", temp->height);
        fprintf(file, "Weight: %.2f\n", temp->weight);
        fprintf(file, "Club: %s\n", temp->club);
        fprintf(file, "Email: %s\n", temp->email);
        fprintf(file, "Player Position: %d\n", temp->playerPosition);
        fprintf(file, "Missed Tackles: %d\n", temp->missedTackles);
        fprintf(file, "Player Metres: %d\n", temp->playerMetres);
        fprintf(file, "\n");
        temp = temp->next;
    }
    fprintf(file, "**********************************************\n");

    fclose(file);
}

// Update the player file with the new details from the linked list
void updatePlayerFile(playerDetails* top) {
    FILE* fp;
    fp = fopen("Rugby.txt", "w");

    if (fp == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }

    playerDetails* temp = top;

    while (temp != NULL) {
        fprintf(fp, "%d %s %s %d %.2f %.2f %s %s %d %d %d\n", temp->irfuNumber,
            temp->firstName, temp->secondName, temp->age, temp->height,
            temp->weight, temp->club, temp->email, temp->playerPosition,
            temp->missedTackles, temp->playerMetres);

        temp = temp->next;
    }

    fclose(fp);
    printf("Rugby.txt file updated successfully!\n");
}

// Function to display player positions (Output)
void displayPlayerPositions() {
    printf("Player Positions:\n");
    printf("1. Prop\n");
    printf("2. Hooker\n");
    printf("3. Second Row\n");
    printf("4. Back Row\n");
    printf("5. Half Back\n");
    printf("6. Centres\n");
    printf("7. Wingers/Full Back\n");
}

// Function to display player metres (Output)
void displayPlayerMetres() {
    printf("How many metres does the player make in a game?\n");
    printf("1. None\n");
    printf("2. Less than 10 metres\n");
    printf("3. Less than 20 metres\n");
    printf("4. More than 20 metres\n");
}

// Function to display missed tackles (Output)
void displayMissedTackles() {
    printf("How many tackles does the player miss per match?\n");
    printf("1. None\n");
    printf("2. Less than 3 tackles\n");
    printf("3. Less than 5 tackles\n");
    printf("4. More than 5 tackles\n");
}

/*
// Function to swap two playerDetails nodes
void swapPlayers(playerDetails* a, playerDetails* b) {
    playerDetails temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort function for sorting players by height
void bubbleSort(playerDetails* top) {
    int swapped;
    playerDetails* ptr1;
    playerDetails* lptr = NULL;

    if (top == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = top;

        while (ptr1->next != lptr) {
            if (ptr1->height > ptr1->next->height) {
                swapPlayers(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// Function to list all players in order of height
void listPlayersByHeight(playerDetails* top) {
    // Sort players by height using Bubble Sort
    bubbleSort(top);

    // Print the sorted players
    printf("************* Players Sorted by Height *************\n");
    playerDetails* temp = top;
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
        temp = temp->next;
    }
    printf("**********************************************\n");
}
*/
