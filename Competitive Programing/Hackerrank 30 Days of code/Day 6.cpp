#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    cin>>n;
    string str1;
    getline(cin,str1);
    for(int i=0;i<n;i++)
    {
        string str;
        getline(cin,str);
        for(int j=0;str[j]!='\0';j++)
        {
            if(j%2==0)
            {
                cout<<str[j];
            }
        }
        cout<<" ";
        for(int j=0;str[j]!='\0';j++)
        {
            if(j%2!=0)
            {
                cout<<str[j];
            }
        }
        cout<<endl;
    }  
    return 0;
}
