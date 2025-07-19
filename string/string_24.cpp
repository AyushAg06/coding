#include<bits/stdc++.h>
using namespace std;
string largestcommonprefix(vector<string>arr)
{
    sort(arr.begin(),arr.end());
    string first=arr.front();
    string last=arr.back();
    int minlen=min(first.length(),last.length());
    int i=0;
    while(i<minlen && first[i]==last[i])
    {
        i++;
    }
    return first.substr(0,i);
}
int main()
{
    vector<string>arr={"greekforgreek","greek","greezer","greed"};
    cout<<largestcommonprefix(arr);
    return 0;
}