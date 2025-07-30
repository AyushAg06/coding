// find the reverse of a string 
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s={"Virat is the greatest odi batter"};
    int start=0,end=s.size()-1;
    while(start<end)
    {
        swap(s[start],s[end]);
        start++;
        end--;
    }
    cout<<s;
    return 0;
}