#include<bits/stdc++.h>
using namespace std;
int fruitintobascket(vector<int>arr)
{
    int maxlen=0;
    for(int i=0;i<arr.size();i++)
    {
        set<int>st;
        for(int j=i;j<arr.size();j++)
        {
            st.insert(arr[j]);
            if(st.size()<=2)
            {
                maxlen=max(maxlen,j-i+1);
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
    vector<int>arr={3,3,3,1,2,1,1,2,3,3,4};
    cout<<fruitintobascket(arr);
    return 0;
}