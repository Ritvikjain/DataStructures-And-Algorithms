#include <bits/stdc++.h>
using namespace std;
int findMinHealth2(int ** input,int si,int sj,int n,int m,int ** dp)
{
    if(si == n-1 && sj == m-1)
        return 1;
    
    if(dp[si][sj] > -1)
        return dp[si][sj];
    int ans1 = INT_MAX;
    int ans2 = INT_MAX;
    if(si < n-1)
        ans1 = findMinHealth2(input,si+1,sj,n,m,dp) - input[si+1][sj];
    if(sj < m-1)
        ans2 = findMinHealth2(input,si,sj+1,n,m,dp) - input[si][sj+1];
    int ans = min(ans1,ans2);
    if(ans < 1)
        ans = 1;
    dp[si][sj] = ans;
    return ans;
}
int findMinHealth(int ** input,int n,int m)
{
    int **dp = new int*[n];
    for(int i=0;i<n;i++)
    {
        dp[i] = new int[m];
    }
    dp[n-1][m-1] = input[n-1][m-1];
    dp[n-2][m-1] = 1;
    dp[n-1][m-2] = 1;
    for(int i=m-3;i>=0;i--)
    {
        dp[n-1][i] = dp[n-1][i+1] - input[n-1][i+1];
        if(dp[n-1][i] < 1)
            dp[n-1][i] = 1;
    }
    for(int i=n-3;i>=0;i--)
    {
        dp[i][m-1] = dp[i+1][m-1] - input[i+1][m-1];
        if(dp[i][m-1] < 1)
            dp[i][m-1] = 1;
    }
    for(int i = n-2;i>=0;i--)
    {
        for(int j = m-2;j>=0;j--)
        {
            int ans1 = dp[i][j+1] - input[i][j+1];
            int ans2 = dp[i+1][j] - input[i+1][j];
            int ans = min(ans1,ans2);
            if(ans<1)
                ans = 1;
            dp[i][j] = ans;
        }
    }
    int ans = dp[0][0];
    for(int i=0;i<n;i++)
    {
        delete [] dp[i];
    }
    delete [] dp;
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        int **input = new int*[n];
        for(int i=0;i<n;i++)
        {
            input[i] = new int[m];
            for(int j=0;j<m;j++)
            {
                cin >> input[i][j];
            }
        }
        int **dp = new int*[n];
        for(int i=0;i<n;i++)
        {
            dp[i] = new int[m];
            for(int j=0;j<m;j++)
            {
                dp[i][j] = -1;
            }
        }
        cout << findMinHealth2(input,0,0,n,m,dp) << endl;
        for(int i=0;i<n;i++)
        {
            delete [] input[i];
            delete [] dp[i];
        }
        delete [] input;
        delete [] dp;
    }
    return 0;
}

