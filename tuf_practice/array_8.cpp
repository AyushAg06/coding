// move zeroes to the end of the array
#include<bits/stdc++.h>
using namespace std;
vector <int> movezeroes(vector<int>arr)
{
    int j=INT_MIN;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]==0)
        {
            j=i;
            break;
        }
    }
    if(j==INT_MIN)
    {
        return arr;
    }
    for(int i=j+1;i<arr.size();i++)
    {
        if(arr[i]!=0)
        {
            swap(arr[i],arr[j]);
            j++;
        }
    }
    return arr;
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
    vector<int>ans=movezeroes(arr);
    cout<<"The array after moving zeroes to the end is: "<<endl;
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    return 0;
}