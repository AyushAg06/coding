#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s="Ayush";
    string m="is Great";
    cout<<s<<endl;
    cout<<m<<endl;
    cout<<s+m<<endl;
    string k;
    cin>>k;
    cout<<k<<endl;
    string l;
    getline(cin,l);
    cout<<l<<endl;
    l.push_back('p');
    cout<<l<<endl;
    l.pop_back();
    cout<<l;
    return 0;
}