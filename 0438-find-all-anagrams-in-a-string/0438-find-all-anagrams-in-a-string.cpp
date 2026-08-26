class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> ans;

        if (s.length() < p.length()) {
            return ans;
        }

        vector<int> need(26, 0);
        vector<int> window(26, 0);

        // Count characters in p
        for (char c : p) {
            need[c - 'a']++;
        }

        int k = p.length();

        for (int i = 0; i < s.length(); i++) {

            // Add current character
            window[s[i] - 'a']++;

            // Keep window size equal to p
            if (i >= k) {
                window[s[i - k] - 'a']--;
            }

            // Check if current window is an anagram
            if (i >= k - 1 && window == need) {
                ans.push_back(i - k + 1);
            }
        }

        return ans;
    }
};