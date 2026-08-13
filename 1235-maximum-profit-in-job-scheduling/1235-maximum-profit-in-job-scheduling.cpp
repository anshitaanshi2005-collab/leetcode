class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {

        int n = startTime.size();

        vector<vector<int>> jobs;

        for (int i = 0; i < n; i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(jobs.begin(), jobs.end());

        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {

            int left = i + 1;
            int right = n - 1;
            int next = n;

            // Find the first job whose start time
            // is >= current job's end time
            while (left <= right) {

                int mid = left + (right - left) / 2;

                if (jobs[mid][0] >= jobs[i][1]) {
                    next = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            int take = jobs[i][2] + dp[next];
            int skip = dp[i + 1];

            dp[i] = max(take, skip);
        }

        return dp[0];
    }
};