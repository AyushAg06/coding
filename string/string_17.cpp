// reverse the words in a string 
// input-Ayush is a good Man 
// output-Man good a is Ayush 
#include<bits/stdc++.h>
using namespace std;
string reversestring(string s)
{
    stringstream ss(s);
    string word;
    vector<string>words;
    while(ss>>word)
    {
        words.push_back(word);
    }
    reverse(words.begin(),words.end());
    string result;
    for(int i=0;i<words.size();i++)
    {
        result+=words[i];
        if(i!=words.size()-1)
        {
            result+=" ";
        }
    }
    return result;
}
int main()
{
    string s="Ayush is a good man";
    cout<<reversestring(s);
    return 0;
}