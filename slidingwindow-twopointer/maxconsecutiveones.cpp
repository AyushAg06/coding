#include<bits/stdc++.h>
using namespace std;
int maxlengthofones(vector<int>arr,int k)
{
    int n=arr.size();
    int maxlen=0;
    for(int i=0;i<n;i++)
    {
        int len=0;
        int zero=0;
        for(int j=i;j<n;j++)
        {
            if(arr[j]==0)
            {
                zero++;
            }
            if(zero<=k)
            {
                len=j-i+1;
                maxlen=max(maxlen,len);
            }
            else{
                break;
            }
        }
    }
    return maxlen;
}
int main()
{
    vector<int>arr={1,1,1,0,0,0,1,1,1,1,0};
    int k=2;
    cout<<maxlengthofones(arr,k);
    return 0;
}