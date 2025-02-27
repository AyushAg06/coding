// find if the string is a anagram or not 
// input-anagram output-naagram 
// every element in string input should be present in the output 
#include<bits/stdc++.h>
using namespace std;
bool anagram(string s,string goal)
{
    if(s.length()!=goal.length())
    {
        return false;
    }
    vector<int>freq(26,0);
    for(int i=0;i<s.size();i++)
    {
        freq[s[i]-'a']++;
        freq[goal[i]-'a']--;
    }
    for(int count:freq)
    {
        if(count!=0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    string s={"anagram"};
    string goal={"naagram"};
    cout<<anagram(s,goal);
    return 0;
}