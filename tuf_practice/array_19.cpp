// two sum problem using 2-pointer approach
#include<bits/stdc++.h>
using namespace std;
vector<int> twosum(vector<int>&arr,int target)
{
    int n=arr.size();
    int left=0,right=n-1;
    sort(arr.begin(),arr.end());
    while(left<right)
    {
        int sum=arr[left]+arr[right];
        if(sum==target)
        {
            return {left,right};
        }
        else if(sum<target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return {};
}
int main()
{
    int n,target;
    cout<<"Enter the size of the array: "<<endl;
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter the elements of the array: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the target value: "<<endl;
    cin>>target;
    vector<int>ans=twosum(arr,target);
    cout<<"The indices of the two numbers are: "<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}