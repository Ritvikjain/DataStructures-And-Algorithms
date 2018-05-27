#include<iostream>
using namespace std;
int main()
{
    long int n;
    cin>>n;
    long int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    long int k;
    cin>>k;
    for(int i=0;i<n;i++)
    {
        if(a[i]==k)
        {
            cout<<i;
            break;
        }
    }
}