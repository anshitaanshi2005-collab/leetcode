class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        // If s1 is longer than s2, permutation is impossible
        if (s1.length() > s2.length())
            return false;

        // Frequency arrays for characters a-z
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        // Store frequency of s1
        for (char ch : s1) {
            freq1[ch - 'a']++;
        }

        // Sliding window over s2
        for (int i = 0; i < s2.length(); i++) {

            // Add current character to window
            freq2[s2[i] - 'a']++;

            // Remove character leaving the window
            if (i >= s1.length()) {
                freq2[s2[i - s1.length()] - 'a']--;
            }

            // Compare both frequency arrays
            if (freq1 == freq2)
                return true;
        }

        return false;
    }
};
