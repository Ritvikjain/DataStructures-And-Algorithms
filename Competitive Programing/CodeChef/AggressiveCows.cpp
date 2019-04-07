#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main() {
	// Write your code here
    int t;
    cin>>t;
    while(t--)
    {
        int n,cows;
        cin>>n>>cows;
        long long pos[n];
        for(int i=0;i<n;i++)
        {
            cin>>pos[i];
        }
        sort(pos,pos+n);
        long long start = 0;
        long long end = pos[n-1] - pos[0];
        long long ans = -1;
        while(start <= end)
        {
            long long mid = (start + end)/2;
            int lastPos = 0;
            long long count = 1;
            for(int i=1;i<n;i++)
            {
                if(pos[i] - pos[lastPos] >= mid)
                {
                    count++;
                    lastPos = i;
                }
                if(count == cows)
                    break;
            }
            if(count == cows)
            {
                start = mid+1;
                ans = mid;
            }
            else
            {
                end = mid-1;
            }
        }
        cout << ans << endl;
    }
}
