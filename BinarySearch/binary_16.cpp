// find the koko banana problem using binary search
#include<bits/stdc++.h>
using namespace std;
int FindMax(vector<int>&piles)
{
    int n=piles.size();
    int maxi=INT_MIN;
    for(int i=0;i<n;i++)
    {
        maxi=max(maxi,piles[i]);
    }
    return maxi;
}
long long CalculateTotalHours(vector<int>&piles,int hourlySpeed)
{
    long long TotalH=0;
    int n=piles.size();
    for(int i=0;i<n;i++)
    {
        TotalH+=(piles[i]+hourlySpeed-1)/hourlySpeed;
    }
    return TotalH;
}
int Binary(vector<int>&piles,int h)
{
    int low=1,high=FindMax(piles);
    int ans=INT_MIN;
    while(low<=high)
    {
        int mid=(low+high)/2;
        long long TotalH=CalculateTotalHours(piles,mid);
        if(TotalH<=h)
        {
            ans=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return ans;
}
int main()
{
    vector<int>piles={3,6,7,11};
    int h=8;
    int result=Binary(piles,h);
    cout<<"Koko can eat maximum of "<<result<<" bananas per hour"<<endl;
    return 0;
}