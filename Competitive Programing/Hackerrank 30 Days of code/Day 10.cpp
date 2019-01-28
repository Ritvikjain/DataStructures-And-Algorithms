#include <bits/stdc++.h>

using namespace std;

long int decToBinary(long int n) 
{ 
    // array to store binary number 
    int binaryNum[1000]; 
  
    // counter for binary array 
    long int i = 0; 
    while (n > 0) { 
  
        // storing remainder in binary array 
        binaryNum[i] = n % 2; 
        n = n / 2; 
        i++; 
    } 
  
    // printing binary array in reverse order 
    long int num=0;
    for (long int j = i - 1; j >= 0; j--) 
        num = num*10 + binaryNum[j];
        
    return num;
} 

int main()
{
    long int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    long int bin=decToBinary(n);
    long int count=0,max=0;
    for(long int i=bin;i!=0;i/=10)
    {
        if(i%10==1)
        {
            count++;
        }
        else
        {
            count=0;
        }
        if(count>=max)
        max=count;
    }
    cout<<count;
    return 0;
}
