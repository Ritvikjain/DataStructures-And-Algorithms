#include<bits/stdc++.h>
using namespace std;
int lcsIterative(char* s1,char* s2)
{
	int m = strlen(s1);
	int n = strlen(s2);
	int **dp = new int*[m+1];
	for(int i=0;i<=m;i++)
	{
		dp[i] = new int[n+1];
	}
	for(int i=0;i<m;i++)
		dp[i][0] = 0;
	for(int i=0;i<n;i++)
	    dp[0][i] = 0;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(s1[m-i] == s2[n-j])
			{
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else{
				dp[i][j] = max( dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	int ans = dp[m][n];
	for(int i=0;i<=m;i++)
		delete [] dp[i];
	delete [] dp;
	return ans;
}
int lcsHelper(char *s1,char *s2,int m,int n,int ** dp){
	if(m == 0 || n == 0)
		return 0;
	if(dp[m][n] > -1)
		return dp[m][n];
	int ans;
	if(s1[0] == s2[0])
		ans = 1 + lcsHelper(s1+1,s2+1,m-1,n-1,dp);
	else{
		int option1 = lcsHelper(s1,s2+1,m,n-1,dp);
		int option2 = lcsHelper(s1+1,s2,m-1,n,dp);
		ans = max(option1,option2);
	}
	dp[m][n] = ans;
	return ans;
}
int lcs(char *s1,char *s2){
	int m = strlen(s1);
	int n = strlen(s2);
	int **dp = new int*[m+1];
	for(int i=0;i<=m;i++)
	{
		dp[i] = new int[n+1];
		for(int j=0;j<=n;j++)
		{
			dp[i][j] = -1;
		}
	}
	int ans = lcsHelper(s1,s2,m,n,dp);
	for(int i=0;i<=m;i++)
		delete [] dp[i];
	delete [] dp;
	return ans;
}
int main()
{
	char s1[100],s2[100];
	cin >> s1 >> s2;
	cout << lcsIterative(s1,s2);
	return 0;
}
