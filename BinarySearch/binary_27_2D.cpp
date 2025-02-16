// search for an element in a 2D matrix using binary search with time complexity log(m*n)
#include<bits/stdc++.h>
using namespace std;
bool SearchBinary(vector<vector<int>>&matrix,int target)
{
    int n=matrix.size();
    int m=matrix[0].size();
    int low=0,high=n*m-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        int row=mid/m;
        int col=mid%m;
        if(matrix[row][col]==target)
        {
            return true;
        }
        else if(matrix[row][col]<target)
        {
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return false;
}
int main()
{
    vector<vector<int>>matrix={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int target=14;
    if(SearchBinary(matrix,target)==true)
    {
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    return 0;
}