#include <bits/stdc++.h>
using namespace std;
int checkSubsetSum(int * arr,int n,int k,int ** dp){
    if(k < 0)
        return 0;
    if(k == 0)
        return 1;
    if(n == 0)
        return 0;
    if(dp[n][k] != -1)
        return dp[n][k];
    int ans = checkSubsetSum(arr,n-1,k-arr[n-1],dp);
    if(ans != 1)
        ans = checkSubsetSum(arr,n-1,k,dp);
    dp[n][k] = ans;
    return ans;
}
int checkSubsetSumIterative(int * arr,int n,int k){
    int ** dp = new int * [2];
    for(int i=0;i<2;i++)
        dp[i] = new int[k+1];
    for(int i=0;i<=k;i++)
        dp[0][i] = 0;
    dp[0][0] = 1;
    int flag = 1;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            dp[flag][j] = dp[flag ^ 1][j];
            if(j>=arr[i-1])
            {
                dp[flag][j] = dp[flag][j] || dp[flag ^ 1][j-arr[i-1]] ;
            }
        }
        flag = flag ^ 1;
    }
    int ans = dp[flag ^ 1][k];
    for(int i=0;i<2;i++)
        delete [] dp[i];
    delete [] dp;
    return ans;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    int ** dp = new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i] = new int[k+1];
        for(int j=0;j<=k;j++)
            dp[i][j] = -1;
    }
    if(checkSubsetSumIterative(arr,n,k))
        cout << "Yes";
    else
        cout << "No";
    for(int i=0;i<=n;i++)
        delete [] dp[i];
    delete [] dp;
    return 0;
}

