// finding the largest substring containing only the unique elements 
// input-ababc
// output-3
#include<bits/stdc++.h>
using namespace std;
int largestsubstring(string s)
{
    unordered_set<char>character;
    int left=0,right=0;
    int maxlen=0;
    while(right<s.size())
    {
        if(character.find(s[right])==character.end())
        {
            character.insert(s[right]);
            maxlen=max(maxlen,right-left+1);
            right++;
        }
        else{
            character.erase(s[left]);
            left++;
        }
    }
    return maxlen;
}
int main()
{
    string s="ababc";
    cout<<largestsubstring(s);
    return 0;
}