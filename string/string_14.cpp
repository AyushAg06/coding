// convert integer to roman values 
// input-1994
// output-MCMXCIV
#include<bits/stdc++.h>
using namespace std;
string integertoroman(int num)
{
    vector<pair<int, string>> roman = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };
    string result="";
    for(auto it:roman)
    {
        while(num>=it.first)
        {
            result+=it.second;
            num-=it.first;
        }
    }
    return result;
}
int main()
{
    int n=1994;
    cout<<integertoroman(n);
    return 0;
}