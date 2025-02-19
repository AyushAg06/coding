// A pangram is a sentence where every letter of the English alphabet appears at least once.
// Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
// Output: true or 1
// Explanation: sentence contains at least one of every letter of the English alphabet.
#include<bits/stdc++.h>
using namespace std;
bool panagram(string sentence)
{
    vector<bool>alphabet(26,0);
    for(int i=0;i<sentence.size();i++)
    {
        int index=sentence[i]-'a';
        alphabet[index]=1;
    }
    for(int i=0;i<26;i++)
    {
        if(alphabet[i]==0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    string s={"thequickbrownfoxjumpsoverthelazydog"};
    cout<<panagram(s);
    return 0;
}