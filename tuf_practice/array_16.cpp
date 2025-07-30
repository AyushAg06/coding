// find the longest subarray with sum k (positive numbers)
#include<bits/stdc++.h>
using namespace std;
int LongestSubArray(vector<int>&arr,int k)
{
    int n=arr.size();
    int i=0,j=0;
    int sum=arr[0];
    int maxi=0;
    while(j<n)
    {
        while(i<=j && sum>k)
        {
            sum=sum-arr[i];
            i++;
        }
        if(sum==k)
        {
            maxi=max(maxi,j-i+1);
        }
        j++;
        if(j<n)
        {
            sum=sum+arr[j];
        }
    }
    return maxi;
}
int main()
{
    int n,k;
    cout<<"Enter the size of the array: "<<endl;
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter the elements of the array: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the value of k: "<<endl;
    cin>>k;
    cout<<"The longest subarray with sum k is: "<<LongestSubArray(arr,k)<<endl;
    return 0;
}