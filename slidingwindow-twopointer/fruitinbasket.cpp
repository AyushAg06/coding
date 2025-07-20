#include<bits/stdc++.h>
using namespace std;
int maximumfruit(vector<int>arr,int k)
{
    int left=0,right=0,maxlen=0;
    int n=arr.size();
    unordered_map<int,int>mpp;
    while(right<n)
    {
        mpp[arr[right]]++;
        if(mpp.size()>k)
        {
            mpp[arr[left]]--;
            if(mpp[arr[left]]==0)
            {
                mpp.erase(arr[left]);
            }
            left++;
        }
        if(mpp.size()==k)
        {
            maxlen=max(maxlen,right-left+1);
        }
        right++;
    }
    return maxlen;
}
int main()
{
    vector<int>arr={3,3,3,1,2,1,1,2,3,3,4};
    int k=2;
    cout<<maximumfruit(arr,k);
    return 0;
}