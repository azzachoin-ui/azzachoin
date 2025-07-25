#include <stdio.h>

#define MAX_VAL 0xfffffff
int n;
int num[10];
int dp[10]={0,};

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
        if(i != 0)
        {
            dp[i] = MAX_VAL;
        }
    }
    for(int i=0;i<n-1;i++)
    {
        if(num[i] !=0)
        {
            for(int j=1;j<=num[i] ;j++)
            {
                if(dp[i+j] > dp[i] + 1)
                {
                    dp[i+j] = dp[i] + 1;
                }
            }
        }
        else
        {
            continue;
        }
    }
    if(dp[n-1] == MAX_VAL ) printf("-1");
    else printf("%d", dp[n-1] );
    return 0;
}

//결국 모든case를 다 따져봐야알것같은데..???