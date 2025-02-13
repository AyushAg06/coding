// find the least capacity of the ship that will take all the packages in D days.
// weight={1,2,3,4,5,6,7,8,9,10}, D=5
// output=15 as 15/5=3,1+2+3+4+5=15
#include<bits/stdc++.h>
using namespace std;
int FindMin(vector<int>&weight)
{
    int maxi=INT_MIN;
    int n=weight.size();
    for(int i=0;i<n;i++)
    {
        maxi=max(maxi,weight[i]);
    }
    return maxi;
}
int FindMax(vector<int>&weight)
{
    int sum=0;
    int n=weight.size();
    for(int i=0;i<n;i++)
    {
        sum+=weight[i];
    }
    return sum;
}
int SumByCapacity(vector<int>&weight,int mid)
{
    int load=0;
    int n=weight.size();
    int days=1;
    for(int i=0;i<n;i++)
    {
        if(load+weight[i]>mid)
        {
            days+=1;
            load=weight[i];
        }
        else
        {
            load+=weight[i];
        }
    }
    return days;
}
int LeastCapacity(vector<int>&weight,int days)
{
    int low=FindMin(weight),high=FindMax(weight);
    int ans=-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(SumByCapacity(weight,mid)<=days)
        {
            ans=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return ans;
}
int main()
{
    vector<int>weight={1,2,3,4,5,6,7,8,9,10};
    int days=5;
    cout<<LeastCapacity(weight,days)<<endl;
    return 0;
}
// Time Complexity: O(nlog(sum(arr)))
// Space Complexity: O(1)