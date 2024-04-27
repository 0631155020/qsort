#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct 
{
    char name[16];
    int score;
    int wins;
}HOUSE;

int cmp(const void* a, const void* b)
{
    HOUSE* left = (HOUSE*) a;//type casting from void* to HOUSE*
    HOUSE* right = (HOUSE*) b;

    if (right->score != left->score)
    {
        return -(left->score-right->score);
    }

    if (right->wins != left->wins)
    {
        return -(left->wins-right->wins);
    }
    
    
}

int main()
{

    char line[101];
    int lenght = atoi(gets(line));

    HOUSE home[lenght];

    for (int i = 1; i <= lenght; i++)
    {
        gets(line);
        strcpy(home[i].name,strtok(line,";"));
        home[i].score = atoi(strtok(NULL,";"));
        home[i].wins = atoi(strtok(NULL,";"));

    }
    

    qsort(home,lenght,sizeof(HOUSE),cmp);

    puts("");
    for (int i = 1; i <= lenght; i++)
    {
        printf("#%d %s: %d(%d)\n",i,home[i].name,home[i].score,home[i].wins);
    }
    

    return EXIT_SUCCESS;
}
