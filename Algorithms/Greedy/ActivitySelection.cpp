#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
struct activity{
    long long start;
    long long end;
};
bool cmp(activity a1,activity a2)
{
    return a1.end<a2.end;
}
long long maxActivities(activity arr[],int n)
{
    long long count = 1;
    long long end = arr[0].end;
    for(int i=1;i<n;i++)
    {
        if(arr[i].start >= end){
            count++;
            end = arr[i].end;
        }
    }
    return count;
}
int main()
{
    //Write your code here
    int n;
    cin>>n;
    struct activity arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].start>>arr[i].end;
    }
    sort(arr,arr+n,cmp);
    // for(int i=0;i<n;i++)
    // {
    //     cout<<arr[i].start<<" "<<arr[i].end<<endl;
    // }
    cout << maxActivities(arr,n);
    return 0;
}
