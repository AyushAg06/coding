#include <bits/stdc++.h>
using namespace std;
void insertion_sort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int j=i;
        while(j>0 && arr[j-1]>arr[j])
        {
            int temp=arr[j-1];
            arr[j-1]=arr[j];
            arr[j]=temp;
            j--;
        }
    }
}
int main()
{
    int n;
    cout<<"enter the value of n:-"<<endl;
    cin>>n;
    int arr[n];
    for(int i;i<n;i++)
    {
        cout<<"enter the elements"<<endl;
        cin>>arr[i];
    }
    insertion_sort(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}