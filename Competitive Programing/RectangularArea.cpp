#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	map<int,int> m;
	int maxRight = 0;
	for(int i=0;i<n;i++)
	{
		int x,y;
		cin >> x >> y;
		if((x/2) > maxRight)
			maxRight = x/2;
		if(y>m[x/2]){
			m[x/2] = y;
		}
	}
	int height = 0,area = 0;
	for(int i = maxRight; i > 0;i--)
	{
		if(m[i] > height)
			height = m[i];
		area += height;
	}
	cout << area*2;
	return 0;
}
