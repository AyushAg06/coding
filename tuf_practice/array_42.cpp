// count inversion in an array using brute force]
#include<bits/stdc++.h>
using namespace std;
int countInversion(vector<int>&arr)
{
    int n=arr.size();
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                count++;
            }
        }
    }
    return count;
}   
int main()
{
    vector<int>arr={2,4,1,3,5};
    cout<<countInversion(arr)<<endl;
    return 0;
}
// Time complexity: O(n^2)
// Space complexity: O(1)