#include<bits/stdc++.h>
using namespace std;
int longestPalindromicSubstring(char s[]) {
	// Write your code here
	int n = strlen(s);
    int maxLen = 0;
    for(int i=0;i<n;i++)
    {
        int l = i;
        int r = i;
        while(l>=0 && r<n && s[l] == s[r])
        {
            int curr = r-l+1;
            if(curr > maxLen)
            	maxLen = curr;
            l--;
            r++;
        }
        if(s[i] == s[i+1])
        {
            l = i;
            r = i+1;
            while(l>=0 && r<n && s[l] == s[r])
            {
                int curr = r-l+1;
                if(curr > maxLen)
                	maxLen = curr;
                l--;
                r++;
            }
        }
    }
    return maxLen;
}
int main(){
	char s[10];
	cin >> s;
	cout << longestPalindromicSubstring(s);
	return 0;
}

