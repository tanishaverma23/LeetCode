#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int minOperations(std::vector<int>& nums, int x) {
        long long totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        long long target = totalSum - x;

        if (target < 0) return -1;
        if (target == 0) return nums.size();

        int maxLen = -1;
        long long currentSum = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); ++right) {
            currentSum += nums[right];

            while (left <= right && currentSum > target) {
                currentSum -= nums[left];
                left++;
            }

            if (currentSum == target) {
                maxLen = std::max(maxLen, right - left + 1);
            }
        }

        return maxLen == -1 ? -1 : nums.size() - maxLen;
    }
};