class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int i = 0;
        int j = numbers.size() - 1;

        while (i < j) {

            int currentSum = numbers[i] + numbers[j];

            if (currentSum == target) {
                return {i + 1, j + 1};
            }

            if (currentSum < target) {
                i++;
            } else {
                j--;
            }
        }

        return {};
    }
};