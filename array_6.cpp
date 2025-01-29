// rotate the array by d places to the left.
#include<bits/stdc++.h>
using namespace std;
void leftrotate(vector<int>&nums,int d)
{
    d=d%nums.size();
    int n=nums.size();
    int temp[d];
    for(int i=0;i<d;i++)
    {
        temp[i]=nums[i];
    }
    for(int i=d;i<n;i++)
    {
        nums[i-d]=nums[i];
    }
    for(int i=0;i<d;i++)
    {
        nums[n-d+i]=temp[i];
    }
}
int main()
{
    int n,d;
    cout<<"Enter the size of the array: "<<endl;
    cin>>n;
    vector<int>nums(n);
    cout<<"Enter the elements of the array: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    cout<<"Enter the number of places by which you want to rotate the array to the left: "<<endl;
    cin>>d;
    leftrotate(nums,d);
    cout<<"The array after left rotation by "<<d<<" places is: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<nums[i]<<" ";
    
    }
    return 0;
}