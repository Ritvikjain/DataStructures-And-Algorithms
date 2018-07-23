#include<iostream>
using namespace std;
int main()
{
    long int n;
    cin>>n;
    long int a[n];
    for(long int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(long int i=0;i<n;i++)
    {
        int count1=0,count2=0;
        for(long int j=i+1;j<n;j++)
        {
            if(a[i]<a[j]&&count1==0)
            {
                count1++;
                for(long int k=j+1;k<n;k++)
                {
                    if(a[j]>a[k]&&count2==0)
                    {
                        count2++;
                        cout<<a[k]<<" ";
                    }
                }
            }
        }
        if(count1==0||count2==0)
        cout<<-1<<" ";
    }
}