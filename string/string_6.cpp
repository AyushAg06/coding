// sort the string in the given sequence 
// Input: s = "Myself2 Me1 I4 and3"
// Output: "Me Myself and I"
#include<bits/stdc++.h>
using namespace std;
string SortSequence(string s)
{
    vector<string>ans(10);
    string temp;
    int count=0,index=0;
    while(index<s.size())
    {
        if(s[index]==' ')
        {
            int pos=temp[temp.size()-1]-'0';//this is used to get the sequence number of that word
            temp.pop_back();//pop's outs the number that is present at the last of the word
            ans[pos]=temp;//it enters the word into that sequence number in the ans string
            temp.clear(); 
            count++;
            index++;
        }
        else{
            temp+=s[index];
            index++;
        }
    }
    int pos=temp[temp.size()-1]-'0';
    temp.pop_back();
    ans[pos]=temp;
    temp.clear();
    count++;
    for(int i=1;i<=count;i++)
    {
        temp+=ans[i];
        temp+=' ';
    }
    temp.pop_back();
    return temp;
}
int main()
{
    string s={"Ayush4 is3 My1 name2"};
    cout<<SortSequence(s);
    return 0;
}
