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
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	ll sum = kadaneAlgo(arr,n);
	cout<<sum;
}
