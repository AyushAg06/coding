// rearrange the array in alternating positive and negative items
#include<bits/stdc++.h>
using namespace std;
vector<int> rearrange(vector<int>&nums)
{
    int n=nums.size();
    vector<int>ans(n,0);
    int posIndex=0;
    int negIndex=1;
    for(int i=0;i<n;i++)
    {
        if(nums[i]<0)
        {
            ans[negIndex]=nums[i];
            negIndex+=2;
        }
        else
        {
            ans[posIndex]=nums[i];
            posIndex+=2;
        }
    }
    return ans;
}
int main()
{
    int n;
    vector<int>nums={-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};	
    vector<int>ans=rearrange(nums);
    cout<<"The rearranged array is: "<<endl;
    for(auto val:ans)
    {
        cout<<val<<" ";
    }
    return 0;
}