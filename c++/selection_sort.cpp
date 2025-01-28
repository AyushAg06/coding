#include <bits/stdc++.h>
using namespace std;
void selection_sort(int arr[],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        int min=i;
        for(j=i;j<n;j++)
        {
            if(arr[j]<arr[min])
            {
                min=j;
            }
        }
        int temp;
        temp=arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
    }
    
}
int main()
{
    int n;
    cout<<"enter the values of n:-"<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    selection_sort(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}