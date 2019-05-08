#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int k;
    cin >> n >> k;
    long long  arr[n];
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    sort(arr,arr+n);
    long long sum[n];
    sum[0] = arr[0];
    for(int i=1;i<n;i++)
        sum[i] = sum[i-1]+arr[i];
    long long target = 0;
    // for(int i=1;i<k;i++)
    // {
    //     target = target + (i*arr[i]) - sum[i-1];
    // }
    for(int i=0; i<k; i++) 
        target+=arr[i]*(2*i-k+1);
    long long res=target; 
    for(int i=0; i<n-k; i++) 
    { 
        target=(target-(2*(sum[i+k-1]-sum[i]))+(k-1)*arr[i]+(k-1)*arr[i+k]);
        res=min(res,target);
    }
    cout << res;
    // int minUnfairness = target;
    // for(int i=1;i+k<=n;i++)
    // {
    //     target = target - 2*(sum[k-2-i]-sum[i-1]) + (k-1)*arr[i-1] + (k-1)*arr[k-1-i];
    //     if(target < minUnfairness)
    //         minUnfairness = target;
    // }
    // cout << minUnfairness << endl;
    return 0;
}

