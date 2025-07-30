// Defanging an IP Address:
// Input: address = "1.1.1.1"
// Output: "1[.]1[.]1[.]1"
#include<bits/stdc++.h>
using namespace std;
string DefangIPAddress(string address)
{
    string ans;
    int index=0;
    while(index<address.size())
    {
        if(address[index]=='.')
        {
            ans+="[.]";
        }
        else{
            ans+=address[index];
        }
        index++;
    }
    return ans;
}
int main()
{
    string s={"1.1.1.1.1"};
    cout<<DefangIPAddress(s);
    return 0;
}