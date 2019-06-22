#include<bits/stdc++.h>
using namespace std;
int* getLPS(string pattern)
{
	int len = pattern.length();
	int * lps = new int[len];
	lps[0] = 0;
	int i=1,j=0;
	while(i<len){
		if(pattern[i] == pattern[j])
		{
			lps[i] = j+1;
			i++;
			j++;
		}
		else{
			if(j!=0)
			{
				j = lps[j-1];
			}
			else{
				lps[i] = 0;
				i++;
			}
		}
	}
	return lps;
}
bool findPatternKMP(string text,string pattern)
{
	int lenTxt = text.length();
	int lenPat = pattern.length();
	
	int * lps = getLPS(pattern);
	int i=0;
	int j=0;
	while(i<lenTxt && j<lenPat)
	{
		if(text[i] == pattern[j])
		{
			i++;j++;
		}else{
			if(j!=0){
				j = lps[j-1];
			}else
			{
				i++;
			}
		}
	}
	if(j == lenPat)
		return true;
	else
		return false;
}
int main()
{
	string text,pattern;
	cin >> text >> pattern;
	cout << findPatternKMP(text,pattern);
	
}
