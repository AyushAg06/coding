// Isomorphic Strings
// input-s=bee,t=egg output=true 
// input-s=bar,t=foo output=false 
#include<bits/stdc++.h>
using namespace std;
bool isomorphic(string s,string t)
{
    if(s.length()!=t.length())
    {
        return false;
    }
    unordered_map<char,char>StoT;
    unordered_map<char,char>TtoS;
    for(int i=0;i<s.size();i++)
    {
        char schar=s[i];
        char tchar=t[i];
        if(StoT.find(schar)!=StoT.end())
        {
            if(StoT[schar]!=tchar)
            {
                return false;
            }
        }
        else{
            StoT[schar]=tchar;
        }
        if(TtoS.find(tchar)!=TtoS.end())
        {
            if(TtoS[tchar]!=schar)
            {
                return false;
            }
        }
        else{
            TtoS[tchar]=schar;
        }
    }
    return true;
}
int main()
{
    string s={"bee"};
    string t={"odd"};
    cout<<isomorphic(s,t);
    return 0;
}