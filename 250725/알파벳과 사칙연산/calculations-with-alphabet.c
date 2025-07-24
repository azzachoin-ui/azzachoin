#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NUM 4
#define CHAR_VAR_NUM 6
#define ACCUM_CASE_NUM 1000000
char formula[201];
int numberArr[CHAR_VAR_NUM];
int resultArr[CHAR_VAR_NUM];
int accumResultArr[ACCUM_CASE_NUM][CHAR_VAR_NUM];
int accumIdx=0;
int numVarCnt=0;
void makeAllCases(int depth)
{
    if(depth ==numVarCnt )
    {
        memcpy(accumResultArr[accumIdx++], resultArr, sizeof(int)*CHAR_VAR_NUM);
        return;
    }
    for(int i=1;    i<= MAX_NUM; i++)
    {
        resultArr[depth]= i;
         makeAllCases( depth+1);
    }
    return;
}
int translateAlphaToNum(char k, int* arr)
{
    if(k =='a')
    {
        return arr[numberArr[0]];
    }
    else if(k =='b')
    {
        return arr[numberArr[1]];
    }
    else if(k =='c')
    {
        return arr[numberArr[2]];
    }
    else if(k =='d')
    {
        return arr[numberArr[3]];
    }
    else if(k =='e')
    {
        return arr[numberArr[4]];
    }
    else if(k =='f')
    {
        return arr[numberArr[5]];
    }
    else{        return 0;}
}
int main() {
    scanf("%s",formula);
    int length = strlen(formula);
    for(int i=0;i<length;i++)
    {
        if(formula[i]=='a')
        {
            numberArr[0]++;
        }
        else if(formula[i]=='b')
        {
            numberArr[1]++;
        }
        else if(formula[i]=='c')
        {
            numberArr[2]++;
        }
        else if(formula[i]=='d')
        {
            numberArr[3]++;
        }
        else if(formula[i]=='e')
        {
            numberArr[4]++;
        }
        else if(formula[i]=='f')
        {
            numberArr[5]++;
        }
        else{}
    }
    for(int i=0;i<CHAR_VAR_NUM;i++)
    {
        if(numberArr[i] != 0)
        {
            numberArr[i] = numVarCnt++;
        }
    }
     makeAllCases(0);
     int maxRslt=-0xfffffff;
     for(int i=0;   i<accumIdx;     i++)
     {
        int tempCalcRslt= translateAlphaToNum(formula[0], accumResultArr[i]);
        for(int j=0;j<(length/2); j++)
        {
            if(formula[j*2+1]=='+')
            {
                tempCalcRslt =  tempCalcRslt + translateAlphaToNum(formula[(j+1)*2], accumResultArr[i]);
            }
            else if(formula[j*2+1]=='-')
            {
                tempCalcRslt =  tempCalcRslt - translateAlphaToNum(formula[(j+1)*2], accumResultArr[i]);
            }
            else if(formula[j*2+1]=='*')
            {
                tempCalcRslt =  tempCalcRslt * translateAlphaToNum(formula[(j+1)*2], accumResultArr[i]);
            }
            else{}
        }
        if(maxRslt < tempCalcRslt)
        {
            maxRslt = tempCalcRslt;
        }
     }
    printf("%d",maxRslt);
    return 0;
}