class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 1;
        int right = arr.size() - 2;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Check if mid is the peak
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
                return mid;
            }
            // If we're in the increasing part, peak is to the right
            else if (arr[mid] < arr[mid + 1]) {
                left = mid + 1;
            }
            // If we're in the decreasing part, peak is to the left
            else {
                right = mid - 1;
            }
        }
        
        return -1; // This line should never be reached for valid input
    }
};