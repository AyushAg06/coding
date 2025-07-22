#include<bits/stdc++.h>
using namespace std;
int atmost(vector<int>arr,int goal)
{
    int left=0,right=0,sum=0,count=0;
    int n=arr.size();
    while(right<n)
    {
        sum=sum+arr[right];
        while(sum>goal)
        {
            sum=sum-arr[left];
            left++;
        }
        count=count+(right-left+1);
        right++;
    }
    return count;
}
int binarysubarray(vector<int>&arr,int goal)
{
    return atmost(arr,goal) - atmost(arr,goal-1);
}
int main()
{
    vector<int>arr={1,0,1,0,1};
    int goal=2;
    cout<<binarysubarray(arr,goal);
    return 0;
}