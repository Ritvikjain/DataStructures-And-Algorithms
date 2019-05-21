#include <bits/stdc++.h>
using namespace std;
int minimumSalary(int * a,int * c,int n,int x,int ** dp){
    if(n==0)
        return 0;
    if(dp[n][x] > -1)
        return dp[n][x];
    int ans = 0;
    if(x == 0)
        ans = a[0] + minimumSalary(a+1,c+1,n-1,1,dp);
    else if(x == n)
        ans = c[0] + minimumSalary(a+1,c+1,n-1,x-1,dp);
    else{
        ans = min(a[0]+minimumSalary(a+1,c+1,n-1,x+1,dp),c[0]+minimumSalary(a+1,c+1,n-1,x-1,dp));
    }
    dp[n][x] = ans;
    return ans;
}
int main()
{
    int n;
    cin >> n;
    int a[n],c[n];
    for(int i=0;i<n;i++){
        cin >> c[i] >> a[i];
    }
    int ** dp = new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i] = new int[n/2 +1];
        for(int j=0;j<=n/2;j++)
            dp[i][j] = -1;
    }
    cout << minimumSalary(a,c,n,0,dp);
    return 0;
}

