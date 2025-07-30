// find missing elements from an array using xor
#include<bits/stdc++.h>
using namespace std;
int missingElement(vector<int>&arr)
{
    int xor1=0,xor2=0;
    int n=arr.size();
    for(int i=0;i<=n;i++)
    {
        xor1=xor1^i;
    }
    for(auto it:arr)
    {
        xor2=xor2^it;
    }
    return xor1^xor2;
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
    cout<<"The missing element is: "<<missingElement(arr)<<endl;
    return 0;
}
