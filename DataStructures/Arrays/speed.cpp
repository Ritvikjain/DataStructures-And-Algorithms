#include<iostream>
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
        int count=0;
        for(int j=0;j<n;j++)
        {
            cin>>a[j];
            /*if(a[j]<a[j-1])
            count++;*/
            int flag=1;
            for(int k=0;k<j;k++)
            {
                if(a[k]<a[j])
                {
                    flag=0;break;
                }
            }
            
            if(flag==1)
            count++;
        }
        cout<<count<<endl;
    }
}