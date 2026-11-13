#include <stdio.h>
#include <stdlib.h>
#include "match.h"

void play_innings(inn_stats *batting, inn_stats *bowling, int max_overs, int is_second_innings, int target)
{

    int max_balls = max_overs * 6;
    int striker = 0;
    int non_striker = 1;
    int next_batsman = 2;
    int bowler = 0;

    printf("\n");
    printf("Start of Innings:\n");
    printf("%s batting\n", batting->team);

    while (batting->deliveries < max_balls && batting->team_wickets < 10)
    {
        #ifdef _WIN32
        system("cls");
        #else
        system("clear");
        #endif


        double overs = batting -> deliveries / 6.0;
        double crr = (overs > 0) ? (batting->team_runs / overs) : 0.0;

        printf("\n[%s] %d / %d (%d.%d Overs) | CRR: %.2f | Bowler: %s\n", batting->team, batting->team_runs, batting->team_wickets, batting->deliveries / 6, batting->deliveries % 6, crr, bowling->blr[bowler].bowler);

        if (is_second_innings)
        {
            int rem_runs = target - batting->team_runs;
            double rem_overs = max_overs - overs;
            double rrr = (rem_overs > 0) ? (rem_runs / rem_overs) : 99;
            printf("Target: %d, | Runs Required: %d | RRR : %.2f\n", target, (target - batting->team_runs), rrr);

        }

        printf("Enter Runs : [0, 1, 2, 3, 4, 6]\nW : [WIDE]\nn : [NO BALL]\no : [WICKET]\ns : [SCORECARD]\n\n");

        char res;

        scanf("%c", &res);

        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        if (res >= '0' && res <= '6')
        {
            int runs = res - '0';
            if (runs == 5)
            {
                continue;
            }

            batting->deliveries++;
            batting->team_runs += runs;
            batting->bts[striker].runs += runs;
            batting->bts[striker].balls++;
            bowling->bts[bowler].runs+= runs;
            bowling->blr[bowler].balls++;

            if (runs == 4)
            {
                batting->bts[striker].fours++;
            }
            if (runs == 6)
            {
                batting->bts[striker].sixes++;
            }

            if (runs % 2 != 0)
            {
                int temp = striker;
                striker = non_striker;
                non_striker = temp;
            }
        }

        else if (res == 'w' || res == 'W')
        {
            batting->ext.wides++;
            batting->team_runs++;
            bowling->blr[bowler].runs++;
        }

        else if (res == 'n' || res =='N')
        {
                        batting->ext.no_balls++;
            batting->team_runs++;
            bowling->blr[bowler].runs++;
            batting->bts[striker].balls++;
        }

        else if (res == 'o' || res == 'O')
        {
            batting->deliveries++;
            batting->team_wickets++;
            batting->bts[striker].balls++;
            bowling->blr[bowler].wickets++;
            bowling->blr[bowler].balls++;
            printf("WICKET\n");

            if (batting->team_wickets < 10)
            {
                striker = next_batsman;
                next_batsman++;
            }
        }

        else if (res == 's' || res == 'S')
        {
            scorecard(batting);
            printf("Return to match\n\n");
            getchar();
            getchar();
        }

        if (is_second_innings && batting->team_runs >= target)
        {
            break;
        }

        if (batting->deliveries > 0 && batting->deliveries % 6 == 0 && res != 6)
        {
            printf("\n\nEND OF OVER.\n\n");
            int temp = striker;
            striker = non_striker;
            non_striker = temp;
            bowler = (bowler + 1) % 10;
        }

    }
}