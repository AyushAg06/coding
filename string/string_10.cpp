// sort the string in an ascending order 
// input-bdcea
// output-abcde
#include<bits/stdc++.h>
using namespace std;
string sortstring(string s)
{
    vector<int>alphabet(26,0);
    for(int i=0;i<s.size();i++)
    {
        int index=s[i]-'a';
        alphabet[index]++;
    }
    string ans;
    for(int i=0;i<26;i++)
    {
        char c='a'+i;
        while(alphabet[i])
        {
            ans+=c;
            alphabet[i]--;
        }
    }
    return ans;
}
int main()
{
    string s={"ccddabe"};
    cout<<sortstring(s);
    return 0;
}
// time complexity-O(n)
// space complexity-O(n)
