// 4 sum problem in an array
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> fourSum(vector<int>&nums,int target)
{
    int n=nums.size();
    vector<vector<int>>ans;
    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i++)
    {
        if(i>0 && nums[i]==nums[i-1])
        {
            continue;
        }
        for(int j=i+1;j<n;j++)
        {
            if(j>i+1 && nums[j]==nums[j-1])
            {
                continue;
            }
            int k=j+1;
            int l=n-1;
            while(k<l)
            {
                int sum=nums[i]+nums[j]+nums[k]+nums[l];
                if(sum<target)
                {
                    k++;
                }
                else if(sum>target)
                {
                    l--;
                }
                else
                {
                    vector<int>temp={nums[i],nums[j],nums[k],nums[l]};
                    ans.push_back(temp);
                    while(k<l && nums[k]==nums[k-1])
                    {
                        k++;
                    }
                    while(k<l && nums[l]==nums[l+1])
                    {
                        l--;
                    }
                    k++;
                    l--;
                }
            }
        }
    }
    return ans;
}
int main()
{
    vector<int>nums={1,0,-1,0,-2,2};
    int target=0;
    vector<vector<int>>ans=fourSum(nums,target);
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