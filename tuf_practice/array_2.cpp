// print the second largest and second smallest element in the array.
#include<bits/stdc++.h>
using namespace std;
int secondlargest(vector<int>&arr,int n)
{
    int largest=arr[0],seclargest=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>largest)
        {
            largest=arr[i];
        }
        else if(arr[i]>seclargest && arr[i]<largest)
        {
            seclargest=arr[i];
        }
    }
    return seclargest;
}
int secondsmallest(vector<int>&arr,int n)
{
    int smallest=arr[0],secsmallest=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<smallest)
        {
            smallest=arr[i];
        }
        else if(arr[i]<secsmallest && arr[i]>smallest)
        {
            secsmallest=arr[i];
        }
    }
    return secsmallest;
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
    cout<<"The second largest element in the array is: "<<secondlargest(arr,n)<<endl;
    cout<<"The second smallest element in the array is: "<<secondsmallest(arr,n)<<endl;
    return 0;
}