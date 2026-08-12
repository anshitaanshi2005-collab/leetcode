class Solution {
public:
    int maxCoins(vector<int>& nums) {

        int n = nums.size();

        vector<int> a;
        a.push_back(1);

        for (int x : nums) {
            a.push_back(x);
        }

        a.push_back(1);

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int len = 1; len <= n; len++) {

            for (int left = 1; left + len - 1 <= n; left++) {

                int right = left + len - 1;

                for (int k = left; k <= right; k++) {

                    int coins = a[left - 1] * a[k] * a[right + 1];

                    coins += dp[left][k - 1];
                    coins += dp[k + 1][right];

                    dp[left][right] = max(dp[left][right], coins);
                }
            }
        }

        return dp[1][n];
    }
};