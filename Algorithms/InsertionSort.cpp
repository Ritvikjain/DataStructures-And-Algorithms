#include<iostream>
using namespace std;
 void insertionSort(int arr[],int n);
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	insertionSort(arr,n);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<endl;
	}
}
void insertionSort(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		int temp=arr[i];
		int j=i;
		while(j>0&&temp<arr[j-1])
		{
			arr[j]=arr[j-1];
			j=j-1;
		}
		arr[j]=temp;
	}
}
