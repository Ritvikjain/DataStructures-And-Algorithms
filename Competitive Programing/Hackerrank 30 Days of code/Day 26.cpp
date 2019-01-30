#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int d1,d2,m1,m2,y1,y2;
    cin>>d1>>m1>>y1>>d2>>m2>>y2;
    if(y1>y2)
    {
        cout<<10000;
    }
    else if(m1>m2&&y1==y2)
    {
        cout<<(m1-m2)*500;
    }
    else if(d1>d2&&m1==m2&&y1==y2)
    {
        cout<<(d1-d2)*15;
    }
    else
    {
        cout<<0;
    }
    return 0;
}
