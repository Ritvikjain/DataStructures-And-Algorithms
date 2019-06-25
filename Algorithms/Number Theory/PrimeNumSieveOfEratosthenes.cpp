#include<bits/stdc++.h>
using namespace std;
void markSieve(int x,bool * isPrime,int n)
{
    int i = x;
    while(x*i <= n)
    {
        isPrime[x*i] = false;
        i++;
    }
}
int makeSieve(int n){
    bool isPrime[n+1];
    for(int i=0;i<=n;i++)
        isPrime[i] = true;
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(isPrime[i])
        {
            markSieve(i,isPrime,n);
        }
    }
    int count = 0;
    for(int i=0;i<=n;i++)
    {
        if(isPrime[i])
            count++;
    }
    return count;
}
int main(){
	// Write your code here
    int n;
    cin >> n;
    cout << makeSieve(n);
	return 0;
}
