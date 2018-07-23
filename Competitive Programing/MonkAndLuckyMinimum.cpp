#include<iostream>
#include<climits>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        long int n;
        cin>>n;
        long int a[n];
        long int min=LONG_MAX;
        for(int j=0;j<n;j++)
        {
            cin>>a[j];
            if(a[j]<min)
            min=a[j];
        }
        long int count=0;
        for(int j=0;j<n;j++)
        {
            if(a[j]==min)
            count++;
        }
        if(count%2==0)
        cout<<"Unlucky"<<endl;
        else
        cout<<"Lucky"<<endl;
    }
}