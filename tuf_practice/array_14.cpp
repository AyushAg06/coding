// find the maximum consecutives of 1's 
#include<bits/stdc++.h>
using namespace std;
int maxones(vector<int>&arr)
{
    int count=0;
    int maxi=0;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]==1)
        {
            count++;
            maxi=max(maxi,count);
        }
        else
        {
            count=0;
        }
    }
    return maxi;
}
int main()
{
    int n;
    cout<<"Enter the size of the array: "<<endl;
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter the elements of the array: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"The maximum consecutive 1's are: "<<maxones(arr)<<endl;
    return 0;
}