// find missing elements from an array
#include<bits/stdc++.h>
using namespace std;
int missingElement(int arr[],int n){
    int hash[n+1]={0};
    for(int i=0;i<=n;i++)
    {
        hash[arr[i]]=1;
    }
    for(int i=1;i<=n;i++)
    {
        if(hash[i]==0)
        {
            cout<<i<<" ";
        }
    }
}
int main()
{
    int arr[]={1,2,3,4,5,7,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    missingElement(arr,n);
    return 0;
}