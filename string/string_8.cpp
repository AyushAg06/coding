// String Rotated by 2 Places in any directions(clockwise and anticlockwise)
// Input: s1 = "amazon", s2 = "azonam"
// Output: true
#include<bits/stdc++.h>
using namespace std;
void rotateanticlockwise(string &s)
{
    char c=s[0];
    int index=1;
    while(index<s.size())
    {
        s[index-1]=s[index];
        index++;
    }
    s[s.size()-1]=c;
}
void rotateclockwise(string &s)
{
    char c=s[s.size()-1];
    int index=s.size()-2;
    while(index>0)
    {
        s[index+1]=s[index];
        index--;
    }
    s[0]=c;
}
bool isRotated(string &s1,string &s2)
{
    if(s1.size()!=s2.size())
    {
        return 0;
    }
    string clockwise,anticlockwise;
    clockwise=s1;
    rotateclockwise(clockwise);
    rotateclockwise(clockwise);
    if(clockwise==s2)
    {
        return 1;
    }
    anticlockwise=s1;
    rotateanticlockwise(anticlockwise);
    rotateanticlockwise(anticlockwise);
    if(anticlockwise==s2)
    {
        return 1;
    }
}
int main() 
{
    string s1 = "abcdef";
    string s2 = "efabcd";
    if (isRotated(s1, s2)) 
    {
        cout << s2 << " is a rotated version of " << s1 << endl;
    } else 
    {
        cout << s2 << " is not a rotated version of " << s1 << endl;
    }
    return 0;
}