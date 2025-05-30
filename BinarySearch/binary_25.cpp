// find the median between the two sorted array 
#include<bits/stdc++.h>
using namespace std;
int median(vector<int>&a,vector<int>&b)
{
    int n1=a.size();
    int n2=b.size();
    int n3=n1+n2;
    int ind2=n3/2;
    int ind1=ind2-1;
    int ind1el=-1,ind2el=-1;
    int i=0,j=0,cnt=0;
    while(i<n1 && j<n2)
    {
        if(a[i]<b[j])
        {
            if (cnt == ind1) ind1el = a[i];
            if (cnt == ind2) ind2el = a[i];
            cnt++;
            i++;
        }
        else if(a[i]>b[j])
        {
            if (cnt == ind1) ind1el = b[j];
            if (cnt == ind2) ind2el = b[j];
            cnt++;
            j++;
        }
    }
    while (i < n1) {
        if (cnt == ind1) ind1el = a[i];
        if (cnt == ind2) ind2el = a[i];
        cnt++;
        i++;
    }
    while (j < n2) 
    {
        if (cnt == ind1) ind1el = b[j];
        if (cnt == ind2) ind2el = b[j];
        cnt++;
        j++;
    }
    if (n3 % 2 == 1) {
        return (double)ind2el;
    }
    else{
        return (double)((double)(ind1el + ind2el)) / 2.0; 
    }
}
int main()
{
    vector<int> a = {1, 4, 7, 10, 12};
    vector<int> b = {2, 3, 6, 15};
    cout << "The median of two sorted array is " << fixed << setprecision(1)
         << median(a, b) << '\n';
}
