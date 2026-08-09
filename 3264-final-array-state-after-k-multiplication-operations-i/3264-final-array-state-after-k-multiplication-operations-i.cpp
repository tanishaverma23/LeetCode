class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        vector<int> ans(nums.size());
        for (int i = 0; i < k; i++) {
            int mini = INT_MAX;
            int ind = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (mini > nums[j]) {
                    mini = nums[j];
                    ind = j;
                }
            }
            nums[ind] = mini * multiplier;
        }
        return nums;
    }
};