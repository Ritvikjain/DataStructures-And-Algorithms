#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int isPrime(long int n)
{
    int flag=1;
    if(n==1)
    return 0;
    for(long int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            flag=0;
            break;
        }
    }
    return flag;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        long int n;
        cin>>n;
        if(isPrime(n))
        cout<<"Prime"<<endl;
        else
        cout<<"Not prime"<<endl;
    } 
    return 0;
}
