#include <bits/stdc++.h>
using namespace std;
double distance(int x1,int y1,int x2,int y2)
{
    return pow(pow(x2-x1,2)+pow(y2-y1,2),0.5);
}
double maxHapppiness(int ** arr,int n,double * dp)
{
    if(n == 0)
        return 0;
    if( n == 1)
        return arr[0][2];
    if(dp[0] > INT_MIN)
        return dp[0];
    double maxHappy = INT_MIN;
    for(int i=1;i<n;i++)
    {
        double smallOutput = maxHapppiness(arr+i,n-i,dp+i);
        smallOutput += arr[0][2];
        double dist = distance(arr[0][0],arr[0][1],arr[i][0],arr[i][1]);
        smallOutput -= dist;
        //cout<<dist<<endl;
        if(smallOutput > maxHappy)
            maxHappy = smallOutput;
    }
    dp[0] = maxHappy;
    return maxHappy;
}
int main()
{
    int n;
    cin>>n;
    int ** arr= new int*[n];
    for(int i=0;i<n;i++)
    {
        arr[i] = new int[3];
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    double * dp = new double[n];
    for(int i=0;i<n;i++)
        dp[i] = INT_MIN;
    printf("%.6f",maxHapppiness(arr,n,dp));
    
    return 0;
}

