// Sort an array of 0's 1's & 2's
#include<bits/stdc++.h>
using namespace std;
vector<int> sortArr(vector<int>&arr)
{
    int low=0,mid=0,high=arr.size()-1;
    while(mid<=high)
    {
        if(arr[mid]==0)
        {
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid],arr[high]);
            high--;
        }
    }
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
    sortArr(arr);
    cout<<"The sorted array is: "<<endl;
    for(auto &val:arr)
    {
        cout<<val<<" ";
    }
    return 0;
}
