#include <iostream>
#include <cmath>
using namespace std;
bool isprime(int n)
{
	if(n==1)
		return false;
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			return false;
		}
	}
	return true;
}
int main() {
	
	// your code here
	long int n;
	cin>>n;
	for(long i=0;i<n;i++)
	{
		long int a,b;
		cin>>a>>b;
		for(long int j=a;j<=b;j++)
		{
			if(isprime(j))
			{
				cout<<j<<endl;
			}
		}
		cout<<endl;
	}
	return 0;
}
