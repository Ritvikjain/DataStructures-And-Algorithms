#include<bits/stdc++.h>
int min(int a,int b)
{
    return a<b?a:b;
}
int findMaxSquareWithAllZeros(int** arr, int row, int col){
    
    /* Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
    int ** maxSq = new int*[row];
    for(int i=0;i<row;i++)
        maxSq[i] = new int[col];
    for(int i=0;i<row;i++)
    {
        if(arr[i][0] == 0)
            maxSq[i][0] = 1;
        else
            maxSq[i][0] = 0;
    }
    for(int j=0;j<col;j++)
    {
        if(arr[0][j] == 0)
            maxSq[0][j] = 1;
        else
            maxSq[0][j] = 0;
    }
    for(int i=1;i<row;i++)
    {
        for(int j=1;j<col;j++)
        {
            if(arr[i][j] == 0){
                int sq = min(maxSq[i-1][j-1],min(maxSq[i-1][j],maxSq[i][j-1]));
                maxSq[i][j] = sq+1;
            }
            else
                maxSq[i][j] = 0;
        }
    }
    int ans = 0;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(maxSq[i][j] > ans)
                ans = maxSq[i][j];
        }
    }
    return ans;
}
