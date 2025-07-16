#include <bits/stdc++.h>
using namespace std;
int trappingrainwater(vector<int> arr) 
{
    int n = arr.size();
    if (n == 0) 
        return 0;
    vector<int> leftMax(n), rightMax(n);
    leftMax[0] = arr[0];
    for (int i = 1; i < n; i++) 
    {
        leftMax[i] = max(leftMax[i - 1], arr[i]);
    }
    rightMax[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) 
    {
        rightMax[i] = max(rightMax[i + 1], arr[i]);
    }
    int total = 0;
    for (int i = 0; i < n; i++) 
    {
        total += min(leftMax[i], rightMax[i]) - arr[i];
    }
    return total;
}
int main()
{
    vector<int>arr={0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<trappingrainwater(arr);
    return 0;
}