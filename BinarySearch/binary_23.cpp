// find the book allocation program using binary search with the given conditions
// ->every student must be allocated atleast one book 
// ->the book should be distributed in a contiguous manner
// ->the maximum pages of the distributed books should be minimum
// ->arr=[25,46,28,49,24],m=4 output-71=25+46
#include<bits/stdc++.h>
using namespace std;
int CountPages(vector<int>&arr,int mid)
{
    int n=arr.size();
    int student=1;
    int pagesStudent=0;
    for(int i=0;i<n;i++)
    {
        if(pagesStudent+arr[i]<=mid)
        {
            pagesStudent+=arr[i];
        }
        else{
            student++;
            pagesStudent=arr[i];
        }
    }
    return student;
}
int FindPages(vector<int>&arr,int m)
{
    int n=arr.size();
    if(m>n)
    {
        return -1;
    }
    int low=*max_element(arr.begin(),arr.end());
    int high=accumulate(arr.begin(),arr.end(),0);
    while(low<=high)
    {
        int mid=(low+high)/2;
        int student=CountPages(arr,mid);
        if(student>m)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return low;
}
int main()
{
    vector<int>arr={25,46,28,49,24};
    int m=4;
    int ans=FindPages(arr,m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}