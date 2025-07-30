// majority element >n/2 times using COUNTER
#include<bits/stdc++.h>
using namespace std;
int majorityElement(vector<int>&nums)
{
    int count=0;
    int element;
    for(int i=0;i<nums.size();i++)
    {
        if(count==0)
        {
            count=1;
            element=nums[i];
        }
        else if(element==nums[i])
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    int cnt=0;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]==element)
        {
            cnt++;
        }
        if(cnt>nums.size()/2)
        {
            return element;
        }
    }
    return -1;
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
    cout<<"The majority element is: "<<majorityElement(nums)<<endl;
    return 0;
}