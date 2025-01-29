// left rotate an array by 1 places
#include<bits/stdc++.h>
using namespace std;
void leftrotate(vector<int>&nums)
{
    int temp=nums[0];
    for(int i=1;i<nums.size();i++)
    {
        nums[i-1]=nums[i];
    }
    nums[nums.size()-1]=temp;
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
    leftrotate(nums);
    cout<<"The array after left rotation by 1 place is: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<nums[i]<<" ";
    }
    return 0;
}