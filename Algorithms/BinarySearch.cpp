#include<iostream>
using namespace std;
int BinarySearch(int a[],int l,int r,int f)
{
	if(l<=r)
	{
		int mid=(l+r)/2;
		if(a[mid]==f)
		{
			return mid;
		}
		else if(f<a[mid])
		{
			r=mid-1;
		}
		else
		{
			l=mid+1;
		}
		BinarySearch(a,l,r,f);
	}
	else
	return -1;
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
	cout<<"Enter no. to search: ";
	int f;
	cin>>f;
	int pos=BinarySearch(arr,0,n-1,f);
	if(pos==-1)
	cout<<"Element not found";
	else
	cout<<"Found at position: "<<pos+1;	
}
