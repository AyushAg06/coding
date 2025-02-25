// find the largest odd digit present in a given string 
// input-52
// output-5
#include<bits/stdc++.h>
using namespace std;
string largestodd(string s)
{
    int index=s.size()-1;
    int number;
    while(index>=0)
    {
        number=s[index]-'0';
        if(number%2!=0)
        {
            return s.substr(0,index+1);
        }
        else
        {
            index--;
        }
    }
    return "";
}
int main()
{
    string s="512";
    cout<<largestodd(s);
    return 0;
}