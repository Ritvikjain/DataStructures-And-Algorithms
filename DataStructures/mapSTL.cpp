#include <iostream>
#include <map>
using namespace std;
int main()
{
	pair <char,int> x;
	map<char,int> m;
	for(char c='a';c<='z';c++)
	{
		x.first = c;
		x.second = (int) c;
		m.insert(x);
	}
	
	map<char,int> :: iterator it;
	//traverse map using iterator
	for(it = m.begin();it!=m.end();it++)
	{
		cout<<(*it).first<<" "<<(*it).second<<endl;
	}
	//traverse map using index
	for(char c='a';c<='z';c++)
	{
		cout<<m[c]<<endl;
	}
	cout<<"Finding Value of k"<<endl;
	it = m.find('k');
	cout<<(*it).second;
}
