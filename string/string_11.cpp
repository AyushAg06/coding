// sort the vawels in a string 
// Input: s = "lEetcOde"
// Output: "lEOtcede"
#include<bits/stdc++.h>
using namespace std;
string sortvawels(string s)
{
    vector<int>UpperCase(26,0);
    vector<int>LowerCase(26,0);
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
        {
            LowerCase[s[i]-'a']++;
            s[i]='#';
        }
        else if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
        {
            UpperCase[s[i]-'A']++;
            s[i]='#';
        }
    }
    string Vawels;
    for(int i=0;i<26;i++)
    {
        char c='A'+i;
        while(UpperCase[i])
        {
            Vawels+=c;
            UpperCase[i]--;
        }
    }
    for(int i=0;i<26;i++)
    {
        char c='a'+i;
        while(LowerCase[i])
        {
            Vawels+=c;
            LowerCase[i]--;
        }
    }
    int first=0,second=0;
    while(second<Vawels.size())
    {
        if(s[first]=='#')
        {
            s[first]=Vawels[second];
            second++;
        }
        first++;
    }
    return s;
}
int main()
{
    string s={"lEetcOde"};
    cout<<sortvawels(s);
    return 0;
}