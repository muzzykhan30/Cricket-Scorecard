#include "match.h"

void play_odi(inn_stats *inn1, inn_stats *inn2)
{
    play_innings(inn1, inn2, 50, 0, 0);

    int target = inn1->team_runs + 1;

    play_innings(inn2, inn1, 50, 1, target);
    
}