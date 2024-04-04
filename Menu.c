#include <stdlib.h>

#include "Login.h"

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

    /*
    //Option 6
    printf("A) %% of players who miss no tackles\n");
    printf("B) %% of players who miss less than 3 tackles per match\n");
    printf("C) %% of players who miss less than 5 tackles per match\n");
    printf("D) %% of players who miss more than 5 tackles per match\n");
    printf("E) %% of players who make no metres in a game\n");
    printf("F) %% of players who make less than 10 metres in a game\n");
    printf("G) %% of players who make less than 20 metres in a game\n");
    printf("H) %% of players who make more than 20 metres in a game\n");
    */
}

void processMenu() {
    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Add player\n");
            break;
        case 2:
            printf("Display all players to screen\n");
            break;
        case 3:
            printf("Display player details\n");
            break;
        case 4:
            printf("Update a player's statistic\n");
            break;
        case 5:
            printf("Delete player\n");
            break;
        case 6:
            do {
                printf("***************** Statistics *****************\n");
                printf("1) %% of players who miss no tackles\n");
                printf("2) %% of players who miss less than 3 tackles per match\n");
                printf("3) %% of players who miss less than 5 tackles per match\n");
                printf("4) %% of players who miss more than 5 tackles per match\n");
                printf("5) %% of players who make no metres in a game\n");
                printf("6) %% of players who make less than 10 metres in a game\n");
                printf("7) %% of players who make less than 20 metres in a game\n");
                printf("8) %% of players who make more than 20 metres in a game\n");
                printf("-1) Return to the main menu\n");
                printf("**********************************************\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);
                switch (choice) {
                case 1:
                    printf(
                        "%% of players who miss no tackles function to be "
                        "implemented\n");
                    break;
                case 2:
                    printf(
                        "%% of players who miss less than 3 tackles per match "
                        "function to be implemented\n");
                    break;
                case 3:
                    printf(
                        "%% of players who miss less than 5 tackles per match "
                        "function to be implemented\n");
                    break;
                case 4:
                    printf(
                        "%% of players who miss more than 5 tackles per match "
                        "function to be implemented\n");
                case 5:
                    printf(
                        "%% of players who make no metres in a game function to be "
                        "implemented\n");
                    break;
                case 6:
                    printf(
                        "%% of players who make less than 10 metres in a game "
                        "function to be implemented\n");
                    break;
                case 7:
                    printf(
                        "%% of players who make less than 20 metres in a game "
                        "function to be implemented\n");
                    break;
                case 8:
                    printf(
                        "%% of players who make more than 20 metres in a game "
                        "function to be implemented\n");
                    break;
                case -1:
                    break;
                default:
                    printf("Invalid choice. Please try again.\n");
                    break;
                }
                break;
            } while (choice != -1);
        case 7:
            printf(
                "Print all player details into a report file function to be "
                "implemented\n");
            break;
        case 8:
            printf(
                "List all players in order of height function to be implemented\n");
            break;
        case 9:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != -1);
}