#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int j=0;j<n;j++)
    {
        string str;
        cin>>str;
        int count=0;
        for(int i=0;str[i]!='\0';i++)
        {
            if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u')
            count++;
            if(str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U')
            count++;
        }
        cout<<count<<endl;
    }
    return 0;
}