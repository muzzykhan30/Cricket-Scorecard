#ifndef INIT_H
#define INIT_H

typedef struct
{

    char team_1 [50];
    char team_2 [50];

    char stadium [100];

    char match_type [50];

    int format;
}matchdetail;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initialization(matchdetail *init);

#endif