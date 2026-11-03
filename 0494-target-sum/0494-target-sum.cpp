class Solution {
    void find(vector<int>& nums, int ind, int& ans, int curr, int target) {
        if (ind == nums.size()) {
            if (curr == target) {
                ans++;
            }
            return;
        }

        find(nums, ind + 1, ans, curr + nums[ind], target);
        find(nums, ind + 1, ans, curr - nums[ind], target);
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans = 0;
        int curr = 0;

        find(nums, 0, ans, curr, target);

        return ans;
    }
};