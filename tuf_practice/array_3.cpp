// check if the array is sorted and rotated
#include<bits/stdc++.h>
using namespace std;
bool check(vector<int>&nums)
{
    int n=nums.size();
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(nums[i]>nums[(i+1)%n])
        {
            count++;
        }
        if(count>1)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n;
    cout<<"Enter the size of the array: "<<endl;
    cin>>n;
    vector<int>nums(n);
    cout<<"Enter the elements of the array: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    if(check(nums))
    {
        cout<<"The array is sorted and rotated."<<endl;
    }
    else
    {
        cout<<"The array is not sorted and rotated."<<endl;
    }
    return 0;
}