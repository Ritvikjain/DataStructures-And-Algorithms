#include<iostream>
#include<stack>
using namespace std;
void showStack(stack<int> s)
{
    stack<int> stk=s;
    while(!stk.empty())
    {
        cout<<stk.top()<<" ";
        stk.pop();
    }
}
int main()
{
	stack<int> st;
	st.push(10);
	st.push(20);
	st.push(30);
	st.push(40);
	st.push(50);
	showStack(st);
	cout<<endl;
	cout<<"Size "<<st.size()<<endl;
	cout<<"Top "<<st.top()<<endl;
	
}