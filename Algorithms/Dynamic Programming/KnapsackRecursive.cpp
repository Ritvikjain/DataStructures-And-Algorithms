#include<bits/stdc++.h>
int knapsackHelper(int* weights, int* values, int n, int maxWeight,int ** dp){
    if(n < 0 || maxWeight <= 0)
        return 0;
    if(dp[n][maxWeight] > -1)
        return dp[n][maxWeight];
    int ans = INT_MIN;
    if(weights[n-1] <= maxWeight)
        ans = values[n-1] + knapsackHelper(weights,values,n-1,maxWeight-weights[n-1],dp);
    ans = max(ans , knapsackHelper(weights,values,n-1,maxWeight,dp));
    dp[n][maxWeight] = ans;
    return ans;
}
int knapsack(int* weights, int* values, int n, int maxWeight){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
  */
    int ** dp = new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i] = new int[maxWeight+1];
        for(int j=0;j<=maxWeight;j++)
        {
            dp[i][j] = -1;
        }
    }
    int ans = knapsackHelper(weights,values,n,maxWeight,dp);
    for(int i = 0;i<=n;i++)
        delete [] dp[i];
    delete [] dp;
    return ans;
}

