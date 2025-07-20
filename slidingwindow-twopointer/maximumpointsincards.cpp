#include<bits/stdc++.h>
using namespace std;
int maximumpoints(vector<int>&arr,int k)
{
    int leftsum=0,rightsum=0;
    int maxsum=0;
    int n=arr.size();
    for(int i=0;i<k;i++)
    {
        leftsum=leftsum+arr[i];
    }
    maxsum=maxsum+leftsum;
    int rightind=n-1;
    for(int j=k-1;j>=0;j--)
    {
        leftsum=leftsum-arr[j];
        rightsum=rightsum+arr[rightind];
        rightind--;
        maxsum=max(maxsum,rightsum+leftsum);
    }
    return maxsum;
}
int main()
{
    vector<int>arr={1,2,3,4,5,6,1};
    int k=3;
    cout<<"the maximum sum of cards:- "<<maximumpoints(arr,k);
    return 0;
}