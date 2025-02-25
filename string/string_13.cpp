// conver roman values to integer values 
// input-MCMXCIV
// output-1994
#include<bits/stdc++.h>
using namespace std;
int nums(char c)
{
    if(c=='I')
    {
        return 1;
    }
    else if(c=='V')
    {
        return 5;
    }
    else if(c=='X')
    {
        return 10;
    }
    else if(c=='L')
    {
        return 50;
    }
    else if(c=='C')
    {
        return 100;
    }
    else if(c=='D')
    {
        return 500;
    }
    else if(c=='M')
    {
        return 1000;
    }
    return 0;
}
int romantointeger(string s)
{
    int sum=0,index=0;
    while(index<s.size()-1)
    {
        if(nums(s[index])<nums(s[index+1]))
        {
            sum-=nums(s[index]);
        }
        else{
            sum+=nums(s[index]);
        }
        index++;
    }
    sum+=nums(s[index]);
    return sum;
}
int main()
{
    string s="MCMXCIV";
    cout<<romantointeger(s);
    return 0;
}