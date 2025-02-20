// perforn addition operation using strings 
// input-num1={"2345"},num2={"45"}
// output-2390
#include<bits/stdc++.h>
using namespace std;
string adds(string num1,string num2)
{
    string ans;
    int index1=num1.size()-1,index2=num2.size()-1;
    int sum=0,carry=0;
    while(index2>=0)
    {
        sum=(num1[index1]-'0')+(num2[index2]-'0')+carry;
        carry=sum/10;
        char c='0'+sum%10;
        ans+=c;
        index1--;
        index2--;
    }
    while(index1>=0)
    {
        sum=(num1[index1]-'0')+carry;
        carry=sum/10;
        char c='0'+sum%10;
        ans+=c;
        index1--;
    }
    if(carry)
    {
        ans+='1';
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
string addstring(string num1,string num2)
{
    if(num1.size()<num2.size())
    {
        return adds(num2,num1);
    }
    else
    {
        return adds(num1,num2);
    }
}
int main()
{
    string num1={"2345"};
    string num2={"22"};
    cout<<addstring(num1,num2);
    return 0;
}