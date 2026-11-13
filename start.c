#include <stdio.h>
#include "init.h"
#include "toss.h"
#include "stats.h"

void play_odi(inn_stats *inn1, inn_stats *inn2);
void play_t20(inn_stats *inn1, inn_stats *inn2);

int main()
{
    matchdetail match;
    inn_stats team1;
    inn_stats team2;

    initialization(&match);

    toss(&match);

    init_inn(&team1, match.team_1);
    init_inn(&team2, match.team_2);

    if (match.format == 1)
    {
        play_odi(&team1, &team2);
    }
    else if (match.format == 2)
    {
        play_t20(&team1, &team2);
    }
    else
    {
        printf("INVALID INPUT\n");
        return 0;
    }

    printf("\nMATCH COMPLETED\n");
    printf("%s: %d/%d\n", team1.team, team1.team_runs, team1.team_wickets);
    printf("%s: %d/%d\n", team2.team, team2.team_runs, team2.team_wickets);

    if (team2.team_runs >= team1.team_runs + 1)
    {
        printf("%s won the match\n", team2.team);
    }

    else if (team1.team_runs > team2.team_runs)
    {
        printf("%s won the match\n", team1.team);
    }

    else
    {
        printf("\nMATCH IS A TIE\n");
    }
    printf("Clear screen and Exit using ENTER\n\n");
    getchar();
    getchar();

    
    return 0;
}