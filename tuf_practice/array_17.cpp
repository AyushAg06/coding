// find the longest subarray with sum k (positive and negative numbers)
#include<bits/stdc++.h>
using namespace std;
int LongestSubArray(vector<int>&arr,int k)
{
    int n=arr.size();
    map<int,int>mp;
    int sum=0;
    int maxi=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+arr[i];
        if(sum==k)
        {
            maxi=max(maxi,i+1);
        }
        int rem=sum-k;
        //Calculate the length and update maxLen:
        if (mp.find(rem) != mp.end()) 
        {
            int len = i - mp[rem];
            maxi = max(maxi, len);
        }

        //Finally, update the map checking the conditions:
        if (mp.find(sum) == mp.end()) {
            mp[sum] = i;
        }
    }
    return maxi;
}
int main()
{
    vector<int> a = { -1, 1, 1};
    int k = 1;
    int len = LongestSubArray(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}
