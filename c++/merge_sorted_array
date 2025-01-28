#include <iostream>
#include <vector>

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    int i = m - 1;  // Pointer for the last element in the "real" nums1
    int j = n - 1;  // Pointer for the last element in nums2
    int k = m + n - 1;  // Pointer for the last position in the merged nums1

    // Traverse the arrays from the back and merge
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    // If there are remaining elements in nums2, copy them over
    while (j >= 0) {
        nums1[k] = nums2[j];
        k--;
        j--;
    }
}

int main() {
    // Example 1
    std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    std::vector<int> nums2 = {2, 5, 6};
    int m = 3, n = 3;
    
    merge(nums1, m, nums2, n);
    
    // Print the merged array
    for (int num : nums1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
