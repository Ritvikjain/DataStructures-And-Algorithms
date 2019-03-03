#include <iostream>
#include <queue>
using namespace std;
void showpq(priority_queue<int> pq)
{
	priority_queue<int> copy = pq;
	while(!copy.empty())
	{
		cout<<copy.top()<<" ";
		copy.pop();
	}
}
int main()
{
	priority_queue<int> pq;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		pq.push(temp);
	}
	showpq(pq);
}
