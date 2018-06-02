#include<iostream>
#include<queue>
using namespace std;
void showQueue(queue<int> q)
{
    queue<int> que=q;
    while(!que.empty())
    {
        cout<<que.front()<<" ";
        que.pop();
    }
}
int main()
{
	queue<int> qu;
	qu.push(10);
	qu.push(20);
	qu.push(30);
	qu.push(40);
	qu.push(50);
	showQueue(qu);
	cout<<endl;
	cout<<"Size "<<qu.size()<<endl;
	cout<<"Front "<<qu.front()<<endl;
	cout<<"Back "<<qu.back();
}