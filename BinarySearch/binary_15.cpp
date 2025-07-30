// find the nth root of a number using binary search
#include<bits/stdc++.h>
using namespace std;
int func(int mid,int n,int m)
{
    int ans=1;
    for(int i=1;i<=n;i++)
    {
        ans=ans*mid;
        if(ans>m)
        {
            return 2;
        }
    }
    if(ans==m)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int NthRoot(int m,int n)
{
    int low=1,high=m;
    while(low<=high)
    {
        int mid=(low+high)/2;
        int midN=func(mid,n,m);
        if(midN==1)
        {
            return mid;
        }
        else if(midN==2)
        {
            high=mid-1;
        }
        else if(midN==0)
        {
            low=mid+1;
        }
    }
    return -1;
}
int main()
{
    int m=16,n=2;
    int result=NthRoot(m,n);
    if(result==-1)
    {
        cout<<"Nth Root not found"<<endl;
    }
    else
    {
        cout<<"Nth Root found:-"<<result<<endl;
    }
    return 0;
}