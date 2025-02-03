// Number of subarray with xor is k
#include<bits/stdc++.h>
using namespace std;
int subArrayXor(vector<int>&arr,int k)
{
    int n=arr.size();
    int count=0;
    for(int i=0;i<n;i++)
    {
        int sumxor=0;
        for(int j=i;j<n;j++)
        {
            sumxor=sumxor^arr[j];
            if(sumxor==k)
            {
                count++;
            }
        }
    }
    return count;
}
int main()
{
    vector<int>arr={4,2,2,6,4};
    int k=6;
    cout<<subArrayXor(arr,k)<<endl;
    return 0;
}
// Time complexity: O(n^2)
// Space complexity: O(1)