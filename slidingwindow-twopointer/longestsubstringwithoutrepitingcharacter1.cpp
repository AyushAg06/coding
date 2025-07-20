#include<bits/stdc++.h>
using namespace std;
int longestsubstring(string s)
{
    int left=0,right=0;
    int n=s.size();
    vector<int>mpp(256,-1);
    int maxlen=0;
    while(right<n)
    {
        if(mpp[s[right]!=-1])
        {
            if(mpp[s[right]]>=left)
            {
                left=mpp[s[right]]+1;
            }
        }
        maxlen=max(maxlen,right-left+1);
        mpp[s[right]]=right;
        right++;
    }
    return maxlen;
}
int main()
{
    string s="abcabcbb";
    cout<<longestsubstring(s);
    return 0;
}