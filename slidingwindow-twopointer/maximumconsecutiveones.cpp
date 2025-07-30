#include<bits/stdc++.h>
using namespace std;
int maximumones(vector<int>arr,int k)
{
    int left=0,right=0;
    int zero=0,maxlen=0,len=0;
    int n=arr.size();
    while(right<n)
    {
        if(arr[right]==0)
        {
            zero++;
        }
        while(zero>k)
        {
            if(arr[left]==0)
            {
                zero--;
            }
            left++;
        }
        if(zero<=k)
        {
            len=right-left+1;
            maxlen=max(maxlen,len);
        }
        right++;
    }
    return maxlen;
}
int main()
{
    vector<int>arr={1,1,1,0,0,0,1,1,1,1,0};
    int k=2;
    cout<<maximumones(arr,k);
    return 0;
}