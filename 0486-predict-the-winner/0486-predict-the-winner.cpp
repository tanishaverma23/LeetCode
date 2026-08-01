class Solution {
public:
    int solve(vector<int>& nums, int i, int j) {

        // Only one element left
        if (i == j)
            return nums[i];

        // Take left
        int left = nums[i] - solve(nums, i + 1, j);

        // Take right
        int right = nums[j] - solve(nums, i, j - 1);

        // Choose the better option
        return max(left, right);
    }

    bool predictTheWinner(vector<int>& nums) {
        return solve(nums, 0, nums.size() - 1) >= 0;
    }
};