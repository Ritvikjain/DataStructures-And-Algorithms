#define MOD 1000000007
int count(int n,int *dp)
{
    if(n == 0)
        return 1;
    if(n == 1)
        return 1;
    if(dp[n] != -1)
        return dp[n];
    long sum = 0;
    for(int k=1;k<=n;k++)
    {
        sum = (sum+(count(k-1,dp)*count(n-k,dp))%MOD)%MOD;
    }
    dp[n] = sum%MOD;
    return sum%MOD;
}

int countBST(int n)
{
  /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    int * dp = new int[n+1];
    for(int i=0;i<=n;i++)
        dp[i] = -1;
    dp[0] = 1;
    dp[1] = 1;
    return count(n,dp);
}



