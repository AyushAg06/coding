// move zeroes to the end of the array
#include<bits/stdc++.h>
using namespace std;
void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int j = 0; // Pointer to keep track of the next position for non-zero elements
    // Step 1: Move all non-zero elements to the front
    for (int i = 0; i < n; i++) {
        if (nums[i] != 0) {
            nums[j] = nums[i];
            j++;
        }
    } 
    // Step 2: Fill the remaining positions with zeros
    for (int i = j; i < n; i++) {
        nums[i] = 0;
    }
}
int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    moveZeroes(nums);
    cout << "Array after moving zeroes to the end: ";
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}