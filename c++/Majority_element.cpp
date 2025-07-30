#include <iostream>
#include <vector>

int majorityElement(std::vector<int>& nums) {
    int candidate = nums[0];  // Initialize the first element as the candidate
    int count = 1;  // Start with a count of 1 for the first candidate

    // Boyer-Moore Voting Algorithm
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == candidate) {
            count++;
        } else {
            count--;
            if (count == 0) {
                candidate = nums[i];  // Change candidate
                count = 1;
            }
        }
    }

    return candidate;  // Return the majority element
}

int main() {
    // Example 1
    std::vector<int> nums1 = {3, 2, 3};
    std::cout << "Majority element: " << majorityElement(nums1) << std::endl;  // Output: 3

    // Example 2
    std::vector<int> nums2 = {2, 2, 1, 1, 1, 2, 2};
    std::cout << "Majority element: " << majorityElement(nums2) << std::endl;  // Output: 2

    return 0;
}
