#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        long int n,m;
        cin>>n>>m;
        int a[n],b[n];
        for(int j=0;j<n;j++)
        {
            cin>>a[j];
        }
        for(int l=0;l<m;l++)
        {
            for(int j=0;j<n;j++)
            {
                if(j==0)
                {
                    //cout<<"j==0"<<a[j+1];
                    if(a[j+1]==1)
                    b[j]=1;
                    else
                    b[j]=0;
                }
                else if(j==n-1)
                {
                    if(a[j-1]==1)
                    b[j]=1;
                    else
                    b[j]=0;
                }
                else
                {
                    if(a[j-1]==1&&a[j+1]==1)
                    b[j]=1;
                    else
                    b[j]=0;
                }
            }
            for(int j=0;j<n;j++)
            a[j]=b[j];
        }
        for(int j=0;j<n;j++)
        {
            cout<<a[j]<<" ";
        }
        cout<<endl;
    }
}