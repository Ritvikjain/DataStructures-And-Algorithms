#include<bits/stdc++.h>
using namespace std;
struct job{
    int start;
    int end;
    int profit;
};
bool cmp(job j1,job j2){
    return j1.end<j2.end;
}
int maxProfit(job arr[],int n)
{
    sort(arr,arr+n,cmp);
    int *dp = new int[n];
    dp[0] = arr[0].profit;
    
    for(int i=1;i<n;i++)
    {
        int including = arr[i].profit;
        int ind = -1;
        int start = 0;
        int end = i-1;
        while(start <= end)
        {
            int mid = (start+end)/2;
            if(arr[mid].end <= arr[i].start)
            {
                ind = mid;
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        if(ind != -1)
            including += dp[ind];
        dp[i] = max(including,dp[i-1]);
    }
    int ans = dp[n-1];
    delete[] dp;
    return ans;
}
int main()
{
    //Write your code here
    int n;
    cin>>n;
    job j[n];
    for(int i=0;i<n;i++)
    {
        cin>>j[i].start>>j[i].end>>j[i].profit;
    }
    cout << maxProfit(j,n);
    return 0;
}
