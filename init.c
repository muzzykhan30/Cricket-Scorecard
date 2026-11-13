#include "init.h"


void initialization(matchdetail *init)
{


    printf("Enter the name of the first team:\n");
    scanf("%[^\n]", init->team_1);

    printf("Enter the name of the second team:\n");
    scanf(" %[^\n]", init->team_2);

    printf("Enter the Venue name:\n");
    scanf(" %[^\n]", init->stadium);

    printf("Choose the format\n[1. ODI]\n[2. T20]\n\n");
    scanf("%d", &init->format);
    
    switch (init->format)
    {
        case 1:
        strcpy(init->match_type, "ODI");
        break;

        case 2:
        strcpy(init->match_type, "T20");
        break;

        
        default:
        printf("ERROR: Invalid Input\n");
        return;
    }

    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif

    printf("\n\nTEAM 1: %s \n\nTEAM 2: %s \n\nFORMAT: %s \n\nVENUE: %s Stadium\n\n", init->team_1, init->team_2, init->match_type, init->stadium);

}