// majority element in an array n>3
#include<bits/stdc++.h>
using namespace std;
vector<int>MajorityElement(vector<int>&nums)
{
    int n=nums.size();
    int count1=0,count2=0;
    int element1,element2;
    for(int i=0;i<n;i++)
    {
        if(count1==0 && nums[i]!=element2)
        {
            count1=1;
            element1=nums[i];
        }
        else if(count2==0 && nums[i]!=element1)
        {
            count2=1;
            element2=nums[i];
        }
        else if(nums[i]==element1)
        {
            count1++;
        }
        else if(nums[i]==element2)
        {
            count2++;
        }
        else
        {
            count1--;
            count2--;
        }		
    }
    vector<int>ans;
    count1=0;
    count2=0;
    int mini=(n/3)+1;
    for(int i=0;i<n;i++)
    {
        if(nums[i]==element1)
        {
            count1++;
        }
        else if(nums[i]==element2)
        {
            count2++;
        }
    }
    if(count1>n/3)
    {
        ans.push_back(element1);
    }
    if(count2>n/3)
    {
        ans.push_back(element2);
    }
    sort(ans.begin(),ans.end());
    return ans;
}
int main()
{
    vector<int>nums={1,1,1,3,3,2,2,2};
    vector<int>ans=MajorityElement(nums);
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    return 0;
}