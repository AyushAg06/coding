// find the maximum number of ones in rows
#include<bits/stdc++.h>
using namespace std;
int lower_Bound(vector<int>&arr,int m,int x)
{
    int low=0,high=m-1;
    int ans=m;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]>=x)
        {
            high=mid-1;
            ans=mid;
        }
        else
        {
            low=mid+1;
        }
    }
    return ans;
}
int rowWithMax1s(vector<vector<int>>&arr,int n,int m)
{
    int index=-1;
    int max_cnt=0;
    for(int i=0;i<n;i++)
    {
        int cnt_ones=m-lower_Bound(arr[i],m,1);
        if(cnt_ones>max_cnt)
        {
            max_cnt=cnt_ones;
            index=i;
        }
    }
    return index;
}
int main()
{
    vector<vector<int>> arr = {{1, 1, 1}, {0, 0, 1}, {0, 0, 0}};
    int n = 3, m = 3;
    cout << "The row with maximum no. of 1's is: " <<
         rowWithMax1s(arr, n, m) << '\n';
    return 0; 
}