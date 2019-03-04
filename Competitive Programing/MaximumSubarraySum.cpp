#include <iostream>
#include <climits>
using namespace std;
int Max_Subarray_Sum(int arr[],int n)
{
	if(n==1)
	{
		return arr[0];
	}
	int m = n/2;
	int leftMSS = Max_Subarray_Sum(arr,m);
	int rightMSS = Max_Subarray_Sum(arr+m,n-m);
	
	int leftsum = INT_MIN,rightsum = INT_MIN,sum = 0;
	for(int i=m;i<n;i++)
	{
		sum += arr[i];
		rightsum = max(rightsum,sum);
	}
	sum = 0;
	for(int i=(m-1);i>=0;i--)
	{
		sum += arr[i];
		leftsum = max(leftsum,sum);
	}
	int ans = max(leftMSS,rightMSS);
	return max(ans,leftsum+rightsum);
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<Max_Subarray_Sum(arr,n);
}
