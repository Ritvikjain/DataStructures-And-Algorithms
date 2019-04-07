#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	vector<int> elements;
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		elements.push_back(temp);
	}
	sort(elements.begin(),elements.end());
	int i=0,j=0;
	int variation=0;
	while(i<n-1&&j<n)
	{
		if(i == j)
		{
			j++;
		}
		if(elements[j]-elements[i] >= k)
		{
			variation += (n-j);
			i++;
		}
		else{
			j++;
		}
	}
	cout << variation << endl;
}
