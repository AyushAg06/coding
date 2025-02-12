// use binary search to find the square root of a number
#include<bits/stdc++.h>
using namespace std;
int SquareRoot(int nums)
{
    int low=1,high=nums;
    int ans=1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(mid*mid<=nums)
        {
            ans=mid;
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return ans;
}
int main()
{
    int nums=30;
    int result=SquareRoot(nums);
    cout<<"Square Root found:-"<<result<<endl;
    return 0;
}