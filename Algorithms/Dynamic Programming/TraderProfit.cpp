#include <bits/stdc++.h>
using namespace std;
int maxProfit(int * arr,int n,int k,int ongoing,int *** dp)
{
    if(n == 0)
        return 0;
    if(dp[n][k][ongoing] > -1)
        return dp[n][k][ongoing];
    int option = maxProfit(arr+1,n-1,k,ongoing,dp);
    if(ongoing)
    {
        option = max(option, maxProfit(arr+1,n-1,k-1,0,dp) + arr[0]);
    }
    else{
        if(k>0)
        {
            option = max(option, maxProfit(arr+1,n-1,k,1,dp) - arr[0]);
        }
    }
    dp[n][k][ongoing] = option;
    return option;
}
int main()
{
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> k >> n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin >> arr[i];
        }
        int *** dp = new int**[n+1];
        for(int i=0;i<=n;i++)
        {
            dp[i] = new int*[k+1];
            for(int j=0;j<=k;j++)
            {
                dp[i][j] = new int[2];
                dp[i][j][0] = -1;
                dp[i][j][1] = -1;
            }
        }
        cout << maxProfit(arr,n,k,0,dp) << endl;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=k;j++)
                delete [] dp[i][j];
            delete [] dp[i];
        }
        delete [] dp;
    }
    return 0;
}

