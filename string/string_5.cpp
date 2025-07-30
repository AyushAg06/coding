// find the length of the longest palindrome that can be formed from the given string 
#include<bits/stdc++.h>
using namespace std;
int LongestPalindrome(string s)
{
    vector<int>Lower(26,0);
    vector<int>Upper(26,0);
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='a')
        {
            Lower[s[i]-'a']++;
        }
        else{
            Upper[s[i]-'A']++;
        }
    }
    int count=0;
    int odd=0;
    for(int i=0;i<26;i++)
    {
        if(Lower[i]%2==0)
        {
            count+=Lower[i];
        }
        else
        {
            count+=Lower[i]-1;
            odd=1;
        }
        if(Upper[i]%2==0)
        {
            count+=Upper[i];
        }
        else
        {
            count+=Upper[i]-1;
            odd=1;
        }
    }
    return count+odd;
}
int main()
{
    string s={"abccccdd"};
    cout<<"The longest palindrome is:- "<<LongestPalindrome(s);
    return 0;
}