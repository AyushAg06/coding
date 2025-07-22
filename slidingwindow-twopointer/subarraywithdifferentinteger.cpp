#include<bits/stdc++.h>
using namespace std;
int subarray(vector<int>arr,int k)
{
    int left=0,right=0,count=0;
    unordered_map<int,int>mpp;
    while(right<arr.size())
    {
        mpp[arr[right]]++;
        while(mpp.size()>k)
        {
            mpp[arr[left]]--;
            if(mpp[arr[left]]==0)
            {
                mpp.erase(arr[left]);
            }
            left++;
        }
        count=count+(right-left+1);
        right++;
    }
    return count;
}
int subarraywithdifferentelement(vector<int>arr,int k)
{
    return subarray(arr,k)-subarray(arr,k-1);
}
int main()
{
    vector<int>arr={1,2,1,2,3};
    int k=2;
    cout<<subarraywithdifferentelement(arr,k);
    return 0;
}