#include<bits/stdc++.h>
using namespace std;
int containallthreecharacter(string s)
{
    int count=0;
    for(int i=0;i<s.size();i++)
    {
        int mpp[3]={0};
        for(int j=i;j<s.size();j++)
        {
            if (s[j] == 'a') mpp[0]=1;
            else if (s[j] == 'b') mpp[1]=1;
            else if (s[j] == 'c') mpp[2]=1;
            if(mpp[0]+mpp[1]+mpp[2]==3)
            {
                count+=1;
            }
        }
    }
    return count;
}
int main()
{
    string s="abcabc";
    cout<<containallthreecharacter(s);
    return 0;
}