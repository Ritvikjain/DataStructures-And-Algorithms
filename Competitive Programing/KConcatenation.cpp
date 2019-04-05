#include<iostream>
#include<climits>
using namespace std;
typedef long long ll;
ll kadaneAlgo(int arr[],int n){
	ll current_sum = 0;
	ll best_sum = INT_MIN;
	for(int i=0;i<n;i++)
	{
		current_sum = current_sum + arr[i];
		if(best_sum < current_sum)
			best_sum = current_sum;
		if(current_sum < 0)
			current_sum = 0;
	}
	return best_sum;
}
ll maxSubArrSum(int arr[],int n,int k)
{
	ll kadaneSum = kadaneAlgo(arr,n);
	if(k==1)
		return kadaneSum;
	ll currPre = 0,currSuff = 0;
	ll maxPre = INT_MIN, maxSuff = INT_MIN;
	for(int i=0;i<n;i++)
	{
		currPre += arr[i];
		maxPre = max(maxPre,currPre);
	}
	ll totalSum = currPre;
	for(int i=n-1;i>=0;i--)
	{
		currSuff += arr[i];
		maxSuff = max(maxSuff,currSuff);
	}
	ll ans;
	if(totalSum<0)
	{
		ans = max(maxSuff+maxPre,kadaneSum);
	}
	else
	{
		ans = max(maxSuff+maxPre+(totalSum*(k-2)),kadaneSum);
	}
	return ans;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		cout << maxSubArrSum(arr,n,k)<<endl;
	}
	return 0;
}
