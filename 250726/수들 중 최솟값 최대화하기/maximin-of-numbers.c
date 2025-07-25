#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 10
#define MAX_CASE 10000000
#define MAX_VAL 0xfffffff

int n;
int grid[10][10];

int visited[10];
int selected[10];
int accumSelected[MAX_CASE][10];
int accumIdx=0;

void makeCases(int depth )
{
    if(depth == n)
    {
        memcpy(accumSelected[accumIdx++], selected, sizeof(int)*n);
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(visited[i] !=1)
        {
            selected[depth] = grid[depth][i];
            visited[i] =1;
            makeCases(depth +1);
            visited[i] =0;
        }
    }
    return;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
     makeCases(0 );
    int maxValOfTotCase=0;
    for(int i=0;i<accumIdx;i++)
    {
        int minValOfThisCase=MAX_VAL;
        for(int j=0;j<n;j++)
        {
            if(minValOfThisCase > accumSelected[i][j] ) minValOfThisCase =  accumSelected[i][j];
        }
        if(maxValOfTotCase < minValOfThisCase ) maxValOfTotCase = minValOfThisCase;
    }
    printf("%d", maxValOfTotCase);
    return 0;
}