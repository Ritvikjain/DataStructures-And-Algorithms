#include <iostream>
using namespace std;
void swap(int *p1,int *p2)
{
  int temp = *p1;
  *p1=*p2;
  *p2=temp;
}
void selectionSort(int arr[],int n)
{
  int min_ind;
  for(int i=0;i<n-1;i++)
  {
    min_ind = i;
    for(int j = i+1;j<n;j++)
    {
      if(arr[j]<arr[min_ind])
        min_ind=j;
    }
    swap(&arr[i],&arr[min_ind]);
  }
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	selectionSort(arr,n);
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
}
