#include<bits/stdc++.h>
using namespace std;
string zigzagword(string parag)
{
    int n=parag.length();
    string ans=" ";
    ans+=parag[0];
    for(int i=1;i<n;i++)
    {
        if(i%2==0)
        {
            ans+=parag[i];
        }
    }
    for(int j=1;j<n;j++)
    {
        if(j%2!=0)
        {
            ans+=parag[j];
        }
    }
    return ans;
}
int main()
{
    cout<<zigzagword("ayush");
    return 0;
}