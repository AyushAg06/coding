// check whether a string is a palindrome or not 
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s={"naman"};
    string m=s;
    int start=0,end=s.size()-1;
    while(start<end)
    {
        swap(s[start],s[end]);
        start++;
        end--;
    }
    if(s==m)
    {
        cout<<"palindrome";
    }
    else{
        cout<<"not palindrome";
    }
    return 0;
}