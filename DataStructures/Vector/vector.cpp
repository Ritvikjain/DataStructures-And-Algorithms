#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> v;
    for(int i=1;i<=10;i++)
    {
        v.push_back(i);
    }
    for(int i=0;i<=10;i++)
    {
        cout<<v.at(i)<<" ";
    }
    cout<<endl;
    cout<<"Front "<<v.front()<<endl;
    cout<<"Back "<<v.back()<<endl;
}