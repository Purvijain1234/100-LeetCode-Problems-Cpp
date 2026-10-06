/*
Problem Number: 154
Problem Name: Find Minimum in Rotated Sorted Array II

LeetCode Link:
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

Difficulty: Hard

Topics:
Array, Binary Search

Approach:
We use binary search to find the minimum element in the
rotated sorted array. Since duplicates are allowed, an
additional case is required when nums[mid] == nums[right].

Steps:

1. Initialize two pointers:
   - left = 0
   - right = n - 1

2. While left < right, calculate the middle index.

3. If nums[mid] > nums[right]:
   - The minimum must be in the right half.
   - Move left to mid + 1.

4. If nums[mid] < nums[right]:
   - The minimum can be at mid or in the left half.
   - Move right to mid.

5. If nums[mid] == nums[right]:
   - We cannot determine which half contains the minimum
     because of duplicates.
   - Safely reduce the search space by moving right one
     position: right--.

6. When left == right, the minimum element is nums[left].

Time Complexity:
O(log n) average case
O(n) worst case due to duplicates

Space Complexity:
O(1)
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while(left < right){
            int mid = left + ( right - left ) / 2;

            // Min in is right half
            if (nums[mid] > nums[right]){
                left = mid + 1;
            }

            // Min is i left half
            else if(nums[mid] < nums[right]){
                right = mid;
            }

            // Dupliacte case
            else {
                right--;
            }
        }
        return nums[left];
    }
};
