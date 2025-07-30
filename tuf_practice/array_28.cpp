// find the next permutation of the given array
#include<bits/stdc++.h>
using namespace std;
vector<int> nextPermutation(vector<int>&nums)
{
    int n=nums.size();
    int index=-1;
    for(int i=n-2;i>=0;i--)
    {
        if(nums[i]<nums[i+1])
        {
            index=i;
            break;
        }
    }
    if(index==-1)
    {
        reverse(nums.begin(),nums.end());
        return nums;
    }
    for(int i=n-1;i>index;i--)
    {
        if(nums[i]>nums[index])
        {
            swap(nums[i],nums[index]);
            break;
        }
    }
    reverse(nums.begin()+index+1,nums.end());
    return nums;
}
int main()
{
    vector<int>nums={1,2,3};
    vector<int>ans=nextPermutation(nums);
    cout<<"The next permutation is: ";
    for(auto val:ans)
    {
        cout<<val<<" ";
    }
    return 0;
}