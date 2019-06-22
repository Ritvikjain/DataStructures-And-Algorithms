#include<bits/stdc++.h>
using namespace std;
void buildZ(int *Z,string str)
{
	int l = 0;
	int r = 0;
	int n = str.length();
	for(int i=1;i<n;i++)
	{
		if(i>r)
		{
			// i does not lie between l and r
			// Z for this doesnt exist
			l=i;
			r=i;
			while(r<n && str[r-l] == str[r])
			{
				r++;
			}
			Z[i] = r-l;
			r--;
		}else{
			int k = i-1;
			if(Z[k]<=r-i){
				//i lies between l and r
				// Z will exist previously
				Z[i] = Z[k];
			}
			else{
				//Some part of Z is already included
				//You have to start matching further
				l=i;
				while(r<n && str[r-l] == str[r])
					r++;
				Z[i] = r-l;
				r--;
			}
		}
	}
}
void searchString(string text,string pattern)
{
	string str = pattern+"$"+text;
	int n = str.length();
	int *Z = new int[n]();
	buildZ(Z,str);
	for(int i=0;i<n;i++)
	{
		if(Z[i] == pattern.length())
		{
			cout << Z[i] - pattern.length() - 1 << endl;
		}
	}
}
int main()
{
	string text,pattern;
	cin >> text >> pattern;
	searchString(text,pattern);
	return 0;
}
