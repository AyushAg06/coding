// Aggressive cows problem
// here we need to place the given number of cows in such a way that the minimum distance between them is the maximum
// arr=[0, 3, 4, 7, 10, 9],cows=4
// output=3
#include<bits/stdc++.h>
using namespace std;
int canWePlace(vector<int>&stalls,int mid,int k)
{
    int n=stalls.size();
    int cntcows=1;
    int last=stalls[0];
    for(int i=0;i<n;i++)
    {
        if(stalls[i]-last>=mid)
        {
            cntcows+=1;
            last=stalls[i];
        }
        if(cntcows>=k)
        {
            return true;
        }
    }
    return false;
}
int aggressiveCows(vector<int>&stalls,int k)
{
    int n=stalls.size();
    sort(stalls.begin(),stalls.end());
    int ans=-1;
    int low=1,high=stalls[n-1]-stalls[0];
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(canWePlace(stalls,mid,k)==true)
        {
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}
int main()
{
    vector<int>stalls={0,3,4,7,10,9};
    int k=4;
    int ans=aggressiveCows(stalls,k);
    cout<<"the maximum possible minimum distance is:-"<<ans<<"\n";
    return 0;
}