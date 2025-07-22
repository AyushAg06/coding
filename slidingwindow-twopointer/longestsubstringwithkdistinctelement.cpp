#include<bits/stdc++.h>
using namespace std;
int longestsubstring(string s,int k)
{
    int maxlen=0;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        unordered_map<char,int>mpp;
        for(int j=1;j<n;j++)
        {
            mpp[s[j]]++;
            if(mpp.size()<=k)
            {
                maxlen=max(maxlen,j-i+1);
            }
            else{
                break;
            }
        }
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