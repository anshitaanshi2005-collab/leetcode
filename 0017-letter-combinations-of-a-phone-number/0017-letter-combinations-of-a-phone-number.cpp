class Solution {
public:

    vector<string> ans;

    string keypad[10] = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void solve(string digits, int index, string current) {

        if (index == digits.size()) {
            ans.push_back(current);
            return;
        }

        int digit = digits[index] - '0';

        for (char ch : keypad[digit]) {
            current.push_back(ch);

            solve(digits, index + 1, current);

            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        if (digits.empty()) {
            return {};
        }

        solve(digits, 0, "");

        return ans;
    }
};