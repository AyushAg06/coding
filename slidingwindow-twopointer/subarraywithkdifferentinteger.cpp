#include<bits/stdc++.h>
using namespace std;
int subarrays(vector<int>arr,int k)
{
    int count=0;
    for(int i=0;i<arr.size();i++)
    {
        unordered_map<int,int>mpp;
        for(int j=i;j<arr.size();j++)
        {
            mpp[arr[j]]++;
            if(mpp.size()==k)
            {
                count++;
            }
            else if(mpp.size()>k){
                break;
            }
        }
    }
    return count;
}
int main()
{
    vector<int>arr={1,2,1,3,4};
    int k=3;
    cout<<subarrays(arr,k);
    return 0;
}