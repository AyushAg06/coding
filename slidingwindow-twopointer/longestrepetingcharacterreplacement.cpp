#include<bits/stdc++.h>
using namespace std;
int longestrepetation(string s,int k)
{
    int maxlen=0;
    for(int i=0;i<s.size();i++)
    {
        vector<int>arr(26,0);
        int changes=0;
        int maxf=0;
        for(int j=i;j<s.size();j++)
        {
            arr[s[j]-'A']++;
            maxf=max(maxf,arr[s[j]-'A']);
            changes=(j-i+1)-maxf;
            if(changes<=k)
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
    string s="AABABBA";
    int k=2;
    cout<<longestrepetation(s,k);
    return 0;
}