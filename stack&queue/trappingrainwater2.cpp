// trapping rain water using two pointers approach 
#include<bits/stdc++.h>
using namespace std;
int trappingrainwater(vector<int>nums)
{
    int n=nums.size();
    int l=0,r=n-1;
    int leftmax=0,rightmax=0;
    int total=0;
    while(l<r)
    {
        if(nums[l]<=nums[r])
        {
            if(leftmax>nums[l])
            {
                total+=leftmax-nums[l];
            }
            else
            {
                leftmax=nums[l];
            }
            l++;
        }
        else{
            if(rightmax>nums[r])
            {
                total+=rightmax-nums[r];
            }
            else
            {
                rightmax=nums[r];
            }
            r--;
        }

    }
    return total;
}
int main()
{
    vector<int>nums={0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<"total rainwater collected:- "<<trappingrainwater(nums);
    return 0;
}