#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main() {
    int i = 4;
    double d = 4.0;
    string s = "HackerRank ";

    
    // Declare second integer, double, and String variables.
    
    // Read and save an integer, double, and String to your variables.
    // Note: If you have trouble reading the entire string, please go back and review the Tutorial closely.
    
    // Print the sum of both integer variables on a new line.
    
    // Print the sum of the double variables on a new line.
    
    // Concatenate and print the String variables on a new line
    // The 's' variable above should be printed first.
    int inum;
    double dnum;
    string str;
    cin>>inum>>dnum>>str;
    int sumi=i+inum;
    double sumd=d+dnum;
    cout<<sumi<<endl;
    printf("%.1f",sumd);
    cout<<endl;
    getline(cin,str);
    string res=s+str;
    for(int i=1;str[i]!='\0';i++)
    {
        s+=str[i];
    }
    cout<<"HackerRank is"+str;
    return 0;
}