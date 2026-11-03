class Solution {
    void help(vector<int>& nums, int ind, int& total,vector<int> &cnt, int k) {

        for (int i = ind; i < nums.size(); i++) {
            if (nums[i] - k >= 0 && cnt[nums[i] - k] != 0 )
                continue;
            cnt[nums[i]]++;
            total++;
            help(nums, i + 1, total,cnt, k);
            cnt[nums[i]]--;
        }
    }

public:
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int total = 0;
        vector<int> cnt(1001, 0);

        help(nums, 0, total, cnt, k);

        return total;
    }
};