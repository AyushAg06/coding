// find the leaders in the array
#include<bits/stdc++.h>
using namespace std;
vector<int> leader(vector<int>&nums)
{
    int n=nums.size();
    vector<int>ans;
    int maxi=INT_MIN;
    for(int i=n-1;i>=0;i--)
    {
        if(nums[i]>maxi)
        {
            ans.push_back(nums[i]);
        }
        maxi=max(maxi,nums[i]);
    }
    sort(ans.begin(),ans.end());
    return ans;
}
int main()
{
    vector<int>nums={16,17,4,3,5,2};
    vector<int>ans=leader(nums);
    cout<<"The leaders in the array are: ";
    for(auto val:ans)
    {
        cout<<val<<" ";
    }
    return 0;
}