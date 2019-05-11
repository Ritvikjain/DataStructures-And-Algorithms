#include<iostream>
using namespace std;
int knapsack(int wt[],int val[],int n,int W)
{
	int ** dp = new int*[n+1];
	for(int i=0;i<=n;i++)
	{
		dp[i] = new int[W+1];
	}
	for(int i=0;i<=n;i++)
		dp[i][0] = 0;
	for(int i=0;i<=W;i++)
		dp[0][i] = 0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=W;j++){
			dp[i][j] = dp[i-1][j];
			if(wt[i-1] <= j)
				dp[i][j] = max(dp[i][j], val[i-1]+dp[i-1][j-wt[i]]);
		}
	}
	int ans = dp[n][W];
	for(int i=0;i<=n;i++)
		delete [] dp[i];
	delete [] dp;
	return ans;
}
int main(){
	int n;
	cin >> n;
	int values[n],weights[n];
	for(int i=0;i<n;i++)
		cin >> values[i];
	for(int i=0;i<n;i++)
		cin >> weights[i];
	int maxWeight;
	cin >> maxWeight;
	cout << knapsack(weights,values,n,maxWeight);
	return 0;
}
