#include<bits/stdc++.h>
#include<map>
using namespace std;
char getChar(int i)
{
	return (char)97+i;
}
void printPalindromicString(string s)
{
	map< char,vector<int> > indexesMap;
	for(int i=0;i<s.length();i++)
	{
		indexesMap[s[i]].push_back(i);
	}
	int oddFreqCount=0;
	for(int i=0;i<26;i++)
	{
		if(indexesMap[getChar(i)].size()%2!=0)
		{
			oddFreqCount++;
		}
	}
	if(oddFreqCount>1)
	{
		cout<<-1<<endl;
		return ;
	}
	int ans[s.length()];
	int start = 0,end = s.length()-1;
	for(int i=0;i<26;i++)
	{
		for(int j=0;j<indexesMap[getChar(i)].size();j+=2)
		{
			if((indexesMap[getChar(i)].size() - j) == 1){
				ans[s.length()/2] = indexesMap[getChar(i)][j];
				continue;
			}
			ans[start++] = indexesMap[getChar(i)][j];
			ans[end--] = indexesMap[getChar(i)][j+1];
		}
	}
	for(int i=0;i<s.length();i++)
	{
		cout<< ans[i] + 1 <<" ";
	}
}
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		string s;
		cin>>s;
		printPalindromicString(s);
		cout<<endl;
	}
}
