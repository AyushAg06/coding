#include<bits/stdc++.h>
using namespace std;
int nos(vector<int>arr,int k)
{
    int left=0,right=0,count=0,sum=0;
    int n=arr.size();
    while(right<n)
    {
        sum=sum+(arr[right]%2);
        if(sum>k)
        {
            sum=sum-(arr[left]%2);
            left++;
        }
        count=count+(right-left+1);
        right++;
    }
    return count;
}
int numberofsubarray(vector<int>arr,int k)
{
    return nos(arr,k)-nos(arr,k-1);
}
int main()
{
    vector<int>arr={1,1,2,1,1};
    int k=3;
    cout<<numberofsubarray(arr,k);
    return 0;
}