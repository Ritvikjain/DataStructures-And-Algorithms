#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    float a,b,c,d;
    cin>>a>>b>>c;
    float tip=a*(b/100);
    float tax=a*(c/100);
    float total=a+tip+tax;
    int tot=(int)total;
    float diff=total-tot;
    if(diff>0.5)
        cout<<"The total meal cost is "<<tot+1<<" dollars.";
    else
        cout<<"The total meal cost is "<<tot<<" dollars.";
    return 0;
}
