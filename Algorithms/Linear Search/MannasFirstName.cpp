#include<iostream>
using namespace std;
int main()
{
    long int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string str;
        cin>>str;
        int suvo=0,suvojit=0;
        for(int j=0;str[j]!='\0';j++)
        {
            if(str[j]=='S'&&str[j+3]=='O'&&str[j+4]=='J'&&str[j+6]=='T')
            suvojit++;
            else if(str[j]=='S'&&str[j+3]=='O')
            suvo++;
        }
        cout<<"SUVO = "<<suvo<<", SUVOJIT = "<<suvojit<<endl;
    }
}