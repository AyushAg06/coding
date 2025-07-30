#include<bits/stdc++.h>
using namespace std;
int longestrepetation(string s,int k)
{
    int left=0,right=0,maxlen=0,maxf=0;
    int n=s.size();
    int arr[26]={0};
    while(right<n)
    {
        arr[s[right]-'A']++;
        maxf=max(maxf,arr[s[right]-'A']);
        if((right-left+1)-maxf>k)
        {
            arr[s[left]-'A']--;
            left++;
        }
        if((right-left+1)-maxf<=k)
        {
            maxlen=max(maxlen,right-left+1);
        }
        right++;
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