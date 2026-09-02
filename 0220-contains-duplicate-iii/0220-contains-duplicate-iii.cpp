class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {

        set<long long> st;

        for (int i = 0; i < nums.size(); i++) {

            // Remove elements which are too far away
            if (i > indexDiff) {
                st.erase(nums[i - indexDiff - 1]);
            }

            // Find the first number >= nums[i] - valueDiff
            auto it = st.lower_bound((long long)nums[i] - valueDiff);

            // Check if that number is within valueDiff
            if (it != st.end() && *it <= (long long)nums[i] + valueDiff) {
                return true;
            }

            st.insert(nums[i]);
        }

        return false;
    }
};