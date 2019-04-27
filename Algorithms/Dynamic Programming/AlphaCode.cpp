#include <bits/stdc++.h>
using namespace std;
long long num_codes(int *input,int size,int arr[]){
    if(size == 1 || size == 0)
        return 1;
    if(arr[size] > 0)
        return arr[size];
    long long output = num_codes(input,size-1,arr);
    if(input[size-2]*10+input[size-1] <= 26){
        output += num_codes(input,size-2,arr);
    }
    long long m = pow(10,9) + 7;
    arr[size] = output%m;
    return output%m;
}
int main()
{
    string str;
    while(cin>>str){
        if(str == "0")
            break;
        int *input = new int[str.length()];
        int flag = 1;
        int k = 0;
        for(int i=0;i<str.length();i++)
        {
            if(str[i] == '0' && str[i-1] == '0')
            {   
                flag = 0;
                break;
            }
            else if(str[i] == '0')
            {
                input[k-1] = input[k-1] * 10;
                if(input[k-1] > 26)
                {
                    flag=0;
                    break;
                }
            }else{
                input[k] = str[i]-'0';
                k++;
            }
        }
        if(flag == 0)
        {
            cout<<0<<endl;
            continue;
        }
        int arr[str.length()+1] = {0};
        cout << num_codes(input,k,arr) << endl;
        delete [] input;
    }
    return 0;
}
