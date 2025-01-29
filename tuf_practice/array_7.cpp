// rotate array by d places to the left
#include<bits/stdc++.h>
using namespace std;
void reverseArray(vector<int>& nums, int start, int end) 
{
    while (start < end) {
        swap(nums[start], nums[end]);
        start++;
        end--;
    }
}
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    // Adjust k to avoid unnecessary rotations
    k = k % n;
    // Step 1: Reverse the entire array
    reverseArray(nums, 0, n - 1);
    // Step 2: Reverse the first k elements
    reverseArray(nums, 0, k - 1);
    // Step 3: Reverse the remaining n-k elements
    reverseArray(nums, k, n - 1);
}
int main() {
    int n, k;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << "Enter the value of k (number of steps to rotate): ";
    cin >> k;
    rotate(nums, k);
    cout << "Array after rotation: ";
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}