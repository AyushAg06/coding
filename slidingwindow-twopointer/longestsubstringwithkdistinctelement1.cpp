#include<bits/stdc++.h>
using namespace std;
int longestsubstring(string s,int k)
{
    int left=0,right=0,maxlen=0;
    int n=s.size();
    unordered_map<char,int>mpp;
    while(right<n)
    {
        mpp[s[right]]++;
        if(mpp.size()>k)
        {
            mpp[s[left]]--;
            if(mpp[s[left]]==0)
            {
                mpp.erase(mpp[s[left]]);
            }
            left++;
        }
        if(mpp.size()<=k)
        {
            maxlen=max(maxlen,right-left+1);
        }
        right++;
    }
    return maxlen;
}
int main()
{
    string s="aaabbccd";
    int k=2;
    cout<<longestsubstring(s,k);
    return 0;
}