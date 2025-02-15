// split-array problem using binary search with the following conditions
// ->each sub-array must have atleast one element
//->the elements in the sub-array must be in contiguous manner
//->we need to return the maximum sub-array with the minimum sum
// ->a = {10, 20, 30, 40} k=2 
// ->output=60
#include<bits/stdc++.h>
using namespace std;
int CountPartition(vector<int>&arr,int mid)
{
    int n=arr.size();
    int sum=0;
    int subarray=1;
    for(int i=0;i<n;i++)
    {
        if(sum+arr[i]<=mid)
        {
            sum+=arr[i];
        }
        else{
            subarray++;
            sum=arr[i];
        }
    }
    return subarray;
}
int Split_array(vector<int> &arr,int k)
{
    int n=arr.size();
    if(k>n)
    {
        return -1;
    }
    int low=*max_element(arr.begin(),arr.end());
    int high=accumulate(arr.begin(),arr.end(),0);
    while(low<=high)
    {
        int mid=(low+high)/2;
        int partition=CountPartition(arr,mid);
        if(partition>k)
        {
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return low;
}
int main()
{
    vector<int> a = {10, 20, 30, 40};
    int k = 2;
    int ans = Split_array(a, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}