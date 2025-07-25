#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VAL 0xfffffff
#define TOTAL_CASE_NUM 1000000
#define MAX_N_M 20
int n, m;
int points[MAX_N_M][2];
int selectedPoints[MAX_N_M][2];

int visited[MAX_N_M];
int resultCur[MAX_N_M];
int resultAccum[TOTAL_CASE_NUM][MAX_N_M];
int accumIdx=0;

void makeCase( int n_cur, int m_cur)
{
    if(n_cur == n)
    {
        if(m_cur == m)
        {
            memcpy( resultAccum[accumIdx++], resultCur, sizeof(int)*n );
        }
        return;
    }
    for(int i=0;    i<=1;   i++)
    {
        resultCur[n_cur] = i;   
        makeCase( n_cur +1 , m_cur+i);
    }
    return;
}


int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i][0], &points[i][1]);
    }
     makeCase( 0,0);
     
    int tempMinVal=MAX_VAL;
    for(int i=0;i<accumIdx;i++)
    {
        int idxThisCase=0;
        for(int j=0;j<n;j++) //10
        {
            if(resultAccum[i][j]==1) //5
            {
                selectedPoints[idxThisCase][0]= points[j][0];
                selectedPoints[idxThisCase][1]= points[j][1];
                idxThisCase++;
            }
        }
        int tempMaxVal=0;
        int tempVal=0;
        for(int k=0;    k<m; k++) //idxThisCase대신 m도 가능함
        {
            for(int l=k;    l<m; l++) //idxThisCase대신 m도 가능함
            {
                tempVal = (selectedPoints[k][0]-selectedPoints[l][0]) * (selectedPoints[k][0]-selectedPoints[l][0]) + (selectedPoints[k][1]-selectedPoints[l][1]) * (selectedPoints[k][1]-selectedPoints[l][1]);
                if(tempMaxVal < tempVal) tempMaxVal = tempVal;
            }
        }
        if(tempMinVal > tempMaxVal) tempMinVal = tempMaxVal;
    }
    printf("%d", tempMinVal);
    return 0;
}