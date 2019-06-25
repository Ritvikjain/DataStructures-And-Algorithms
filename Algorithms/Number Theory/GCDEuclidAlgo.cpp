#include<bits/stdc++.h>
int gcd(int a,int b)
{
	//Write your code here
    if(b == 0)
        return a;
    return a>b ? gcd(b,a%b) : gcd(a,b%a);
}

int main()
{
	int a,b;
	cin >> a >> b;
	cout << gcd(a,b);
	return 0;
}
