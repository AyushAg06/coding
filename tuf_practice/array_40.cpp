// merge the overlapping intervals
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> mergeIntervals(vector<vector<int>>&nums)
{
    int n=nums.size();	
    vector<vector<int>>ans;
    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i++)
    {
        if(ans.empty()|| nums[i][0]> ans.back()[1])
        {
            ans.push_back(nums[i]);
        }
        else
        {
            ans.back()[1]=max(ans.back()[1],nums[i][1]);
        }	
    }
    return ans;
}
int main()
{
    vector<vector<int>>nums={{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>>ans=mergeIntervals(nums);
    for(auto it:ans)
    {
        for(auto ele:it)
        {
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;
}