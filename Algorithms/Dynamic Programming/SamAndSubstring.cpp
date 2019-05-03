#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long sumSubstr(string str,int n)
{
	if( n == 0)
	return 0;
	long sum = sumSubstr(str,n-1);
	sum += ((sum*10)%MOD + ((str[n-1]-'0')*n)%MOD)%MOD;
	return sum;
}
int main()
{
	string str;
	cin >> str;
	cout << sumSubstr(str,str.length());
}
