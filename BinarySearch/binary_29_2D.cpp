// find the peak element in a 2D array using binary search
#include<bits/stdc++.h>
using namespace std;
int peakElement(vector<vector<int>>&matrix,int n,int m,int mid)
{
    int maxValue=-1;
    int index=-1;
    for(int i=0;i<n;i++)
    {
        if(matrix[i][mid]>maxValue)
        {
            maxValue=matrix[i][mid];
            index=i;
        }
    }
    return index;
}
vector<int> FindPeak(vector<vector<int>>&matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();
    int low=0,high=m-1;
    while(low<high)
    {
        int mid=(low+high)/2;
        int MaxRowIndex=peakElement(matrix,n,m,mid);
        int left=mid-1>=0 ? matrix[MaxRowIndex][mid-1]:-1;
        int right=mid+1<m ? matrix[MaxRowIndex][mid+1]:-1;
        if(matrix[MaxRowIndex][mid]>left && matrix[MaxRowIndex][mid]>right)
        {
            return {MaxRowIndex,mid};
        }
        else if(matrix[MaxRowIndex][mid]<left)
        {
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return{-1,-1};
}
int main()
{
    vector<vector<int>>matrix={{10,20,15},{21,30,14},{7,16,32}};
    vector<int> ans=FindPeak(matrix);
    cout<<ans[0]<<","<<ans[1]<<endl;
    return 0;
}
