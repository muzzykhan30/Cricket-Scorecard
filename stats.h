#ifndef STATS_H
#define STATS_H
typedef struct
{
    char batsman[30];
    int runs;
    int balls;
    float str;
    int fours;
    int sixes;
} batsman;

typedef struct
{
    char bowler[30];
    int balls;
    int runs;
    int wickets;
} bowler;

typedef struct
{
    int wides;
    int no_balls;
    int byes;
    int leg_byes;
} extras;

typedef struct stats
{
    char team[20];
    int team_runs;
    int team_wickets;
    int deliveries;
    batsman bts[11];
    bowler blr[10];
    extras ext;
} inn_stats;

void init_inn(inn_stats *inn, const char *team);
void scorecard(const inn_stats *inn);

#endif
