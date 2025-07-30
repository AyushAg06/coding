#include<bits/stdc++.h>
using namespace std;
vector<int>asteroidCollision(vector<int>arr)
{
    vector<int>ans;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]>0)
        {
            ans.push_back(arr[i]);
        }
        else{
            while(!ans.empty() && ans.back()<abs(arr[i]))
            {
                ans.pop_back();
            }
            if(!ans.empty() && ans.back()==abs(arr[i]))
            {
                ans.pop_back();
            }
            else if(ans.empty() || ans.back()<0)
            {
                ans.push_back(arr[i]);
            }
        }
    }
    return ans;
}
int main()
{
    vector<int>arr={4,7,1,1,-7,17,15,-16};
    vector<int>ans=asteroidCollision(arr);
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    return 0;
}