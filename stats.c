#include <stdio.h>
#include <string.h>
#include "stats.h"

void init_inn(inn_stats *inn, const char *team)
{
    memset(inn, 0, sizeof(inn_stats));
    strncpy(inn->team, team, sizeof(inn->team) - 1);

    inn->team[sizeof(inn->team) - 1] = '\0';

    for (int i = 0; i < 11; i++)
    {
        sprintf(inn->bts[i].batsman, "Player %d", i + 1);
        inn->bts[i].fours = 0;
        inn->bts[i].sixes = 0;
    }

    for (int j = 0; j < 10; j++)
    {
        sprintf(inn->blr[j].bowler, "Bowler %d", j + 1);
    }
}

void scorecard(const inn_stats *inn)
{
    int overs = inn->deliveries / 6;
    int balls = inn->deliveries % 6;

    printf("\n--- %s --- %d/%d (%d.%d)---\n", inn->team, inn->team_runs, inn->team_wickets, overs, balls);

    printf("\n");

    for (int i = 0; i < 11; i++)
    {
        if (inn->bts[i].balls > 0)
        {
            printf("%s: %d runs (%d balls)\n", inn->bts[i].batsman, inn->bts[i].runs, inn->bts[i].balls);
        }

    }
    printf("\n");
}