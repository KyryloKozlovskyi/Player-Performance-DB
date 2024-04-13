#include <stdlib.h>

#include "Login.h"
#include "Player.h"

void displayMenu() {
    printf("******************** Menu ********************\n");
    printf("1) Add player\n");
    printf("2) Display all players to screen\n");
    printf("3) Display player details\n");
    printf("4) Update a player's statistic\n");
    printf("5) Delete player\n");
    printf("6) Generate statistics based on a range of player weights\n");
    printf("7) Print all player details into a report file\n");
    printf("8) List all the players in order of height\n");
    printf("-1) Exit\n");
    printf("**********************************************\n");
}

void processMenu(playerDetails* top) {
    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addPlayer(&top);
            break;
        case 2:
            displayAllPlayers(top);
            break;
        case 3:
            displayPlayer(top);
            break;
        case 4:
            updatePlayer(top);
            break;
        case 5:
            deletePlayer(&top);
            break;
        case 6:
            generateStatistics(top);
            break;
        case 7:
            printf(
                "Print all player details into a report file function to be "
                "implemented\n");
            break;
        case 8:
            printf(
                "List all players in order of height function to be implemented\n");
            break;
        case -1:
            system("cls");
            printf("Exiting...\n");
            Sleep(500);
            break;
        default:
            system("cls");
            printf("Invalid choice. Please try again.\n");
            Sleep(500);
            system("cls");
        }
    } while (choice != -1);
}
