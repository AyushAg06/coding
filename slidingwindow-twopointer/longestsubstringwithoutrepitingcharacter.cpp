#include<bits/stdc++.h>
using namespace std;
int longestsubstring(string s)
{
    int ans=0;
    for(int i=0;i<s.size();i++)
    {
        unordered_set<char>set;
        for(int j=i;j<s.size();j++)
        {
            if(set.find(s[j])!=set.end())
            {
                ans=max(ans,j-i);
                break;
            }
            set.insert(s[i]);
        }
    }
    return ans;
}
int main()
{
    string s="abcabcbb";
    cout<<longestsubstring(s);
    return 0;
}