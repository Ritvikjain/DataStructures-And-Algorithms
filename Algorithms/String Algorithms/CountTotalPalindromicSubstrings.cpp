#include<bits/stdc++.h>
int countPalindromeSubstrings(char s[]) {
	// Write your code here
	int n = strlen(s);
    int count = 0;
    for(int i=0;i<n;i++)
    {
        //for odd palindromes
        int l = i;
        int r = i;
        while(l>=0 && r<n && s[l] == s[r])
        {
            count++;
            l--;
            r++;
        }
        //for even palindromes
        l = i;
        r = i+1;
        while(l>=0 && r<n && s[l] == s[r])
        {
            count++;
            l--;
            r++;
        }
    }
    return count;
}
int main()
{
	char str[10000];
	cin >> str;
	cout << countPalindromeSubstrings(str);
}

