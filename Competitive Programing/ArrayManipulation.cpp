#include<iostream>
using namespace std;

int main()
{
    long int n;
    long int m;
    cin>>n>>m;
    long int arr[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=0;
    }
    for(int i=0;i<m;i++)
    {
        long int a,b,k;
        cin>>a>>b>>k;
        for(int j=a-1;j<b;j++)
        {
            arr[j] = arr[j]+k;
        }
    }
    long int max=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }
    cout<<max;
}