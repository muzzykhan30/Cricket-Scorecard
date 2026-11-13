#include "match.h"

void play_t20(inn_stats *inn1, inn_stats *inn2)
{
    play_innings(inn1, inn2, 20, 0, 0);

    int target = inn1->team_runs + 1;

    play_innings(inn2, inn1, 20, 1, target);
    
}