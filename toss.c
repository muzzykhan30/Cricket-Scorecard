#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "init.h"


void toss(matchdetail *init)
{

    srand(time(NULL));

    printf("Coin Toss\n1. Heads\n2. Tails\n");
    int call = 0;

    scanf("%d", &call);

    if (call == 1)
    {
        printf("%s calls heads\n", init->team_1);
    }
    else if (call == 2)
    {
        printf("%s calls tails\n", init->team_2);
    }
    else
    {
        printf("INVALID OPTION");
        return;
    }

    --call;

    int toss = rand() % 2;

    if (toss == call)
    {
        printf("%s won the toss\n", init->team_1);
    }
    else if (toss != call)
    {
        printf("%s won the toss\n", init->team_2);
    }

    printf("Choose\n1. Batting\n2. Bowling\n");
    int b_b;
    scanf("%d", &b_b);
    if (b_b == 1)
    {
        printf("Choose to bat first\n");
    }
    else if(b_b == 2)
    {
        printf("Choose to bowl first\n");
    }
    else
    {
        printf("INVALID INPUT\n");
    }

}
