#include<bits/stdc++.h>
using namespace std;
vector<int>generatecols(int rows)
{
    vector<int>ans;
    ans.push_back(1);
    int ans1=1;
    for(int i=1;i<rows;i++)
    {
        ans1=ans1*(rows-i);
        ans1=ans1/i;
        ans.push_back(ans1);
    }
    return ans;
}
vector<vector<int>>pascals(int rows)
{
    vector<vector<int>>result;
    for(int i=0;i<=rows;i++)
    {
        result.push_back(generatecols(i));
    }
    return result;
}
int main()
{
    int rows=5;
    vector<vector<int>>triangle=pascals(rows);
    for(auto it:triangle)
    {
        for(auto rev:it)
        {
            cout<<rev<<" ";
        }
        cout<<endl;
    }
    return 0;
}