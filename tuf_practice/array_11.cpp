// intersection of two sorted array 
#include<bits/stdc++.h>
using namespace std;
vector <int> intersection(vector<int> &arr1,vector<int>&arr2)
{
    int i=0;
    int j=0;
    vector<int>ans;
    int n=arr1.size();
    int m=arr2.size();
    while(i<n && j<m)
    {
        if(arr1[i]<arr2[j])
        {
            i++;
        }
        else if(arr2[j]<arr1[i])
        {
            j++;
        }
        else
        {
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    return ans;
}
int main()
{
    int n,m;
    cout<<"Enter the size of the first array: "<<endl;
    cin>>n;
    vector<int>arr1(n);
    cout<<"Enter the elements of the first array: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr1[i];
    }
    cout<<"Enter the size of the second array: "<<endl;
    cin>>m;
    vector<int>arr2(m);
    cout<<"Enter the elements of the second array: "<<endl;
    for(int i=0;i<m;i++)
    {
        cin>>arr2[i];
    }
    vector<int>ans=intersection(arr1,arr2);
    cout<<"Intersection of the two arrays is: "<<endl;
    for(auto &val:ans)
    {
        cout<<val<<" ";
    }
    return 0;
}