class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // Check if mid is even or odd
            // In a perfect pairs array, each pair starts at even index
            
            // If mid is odd, compare with previous element
            // If mid is even, compare with next element
            if (mid % 2 == 0) {
                // Even index - should be first element of a pair
                if (mid + 1 < nums.size() && nums[mid] == nums[mid + 1]) {
                    // Pair is valid, single element is on the right
                    left = mid + 2;
                } else {
                    // Pair is broken, single element is on the left
                    right = mid;
                }
            } else {
                // Odd index - should be second element of a pair
                if (mid - 1 >= 0 && nums[mid] == nums[mid - 1]) {
                    // Pair is valid, single element is on the right
                    left = mid + 1;
                } else {
                    // Pair is broken, single element is on the left
                    right = mid - 1;
                }
            }
        }
        
        return nums[left];
    }
};