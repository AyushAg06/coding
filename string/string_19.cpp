// find the longest prefix from the given string 
// input-{"flower", "flow", "flight"}
// output-fl 
#include<bits/stdc++.h>
using namespace std;
string longestprefix(vector<string>&str)
{
    if(str.empty())
    {
        return "";
    }
    string prefix=str[0];
    for(int i=0;i<str.size();i++)
    {
        while(str[i].find(prefix)!=0)
        {
            prefix=prefix.substr(0,prefix.size()-1);
            if(prefix.empty())
            {
                return "";
            }
        }
    }
    return prefix;
}
int main()
{
    vector<string> str={"flower", "flow", "flight"};
    cout<<longestprefix(str);
    return 0;
}