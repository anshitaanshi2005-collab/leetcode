class Solution {
public:
    void solve(int open, int close, int n, string curr, vector<string>& ans) {
        // We have used all brackets
        if (curr.size() == 2 * n) {
            ans.push_back(curr);
            return;
        }

        // We can add '(' if we still have some left
        if (open < n) {
            solve(open + 1, close, n, curr + "(", ans);
        }

        // We can add ')' only if there is an unmatched '('
        if (close < open) {
            solve(open, close + 1, n, curr + ")", ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        solve(0, 0, n, "", ans);

        return ans;
    }
};