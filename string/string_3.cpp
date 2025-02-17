// Find the size of the string 
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s={"Ayush is a good enginner"};
    int size=0;
    while(s[size]!='\0')
    {
        size++;
    }
    cout<<size;
    return 0;
}