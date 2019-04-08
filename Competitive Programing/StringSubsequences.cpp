#include<iostream>
using namespace std;
int subSeq(string input,string output[])
{
	if(input.empty())
	{
		output[0] = "";
		return 1;
	}
	string smallString = input.substr(1);
	int smallStringSize = subSeq(smallString,output);
	for(int i=0;i<smallStringSize;i++)
	{
		output[i+smallStringSize] = input[0] + output[i];
	}
	return smallStringSize*2;
}
int main()
{
	string str;
	cin>>str;
	string* output = new string[1000];
	int count = subSeq(str,output);
	for(int i=0;i<count;i++)
	{
		cout << output[i] << endl;
	}
	return 0;
}
