class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int end = 0;
        int farthest = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            farthest = max(farthest, i + nums[i]);

            // We have reached the end of the current jump
            if (i == end) {
                jumps++;
                end = farthest;
            }
        }

        return jumps;
    }
};