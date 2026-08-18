class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt1 = 0;
        int cnt2 = 0;
        if (k == 1) {
            unordered_map<int, int> freq;
            for (int i = 0; i < n; i++) {
                freq[nums[i]]++;
            }
            int maxi = -1;
            for (auto& it : freq) {

                if (it.second == 1) {
                    maxi = max(maxi, it.first);
                }
            }
            return maxi;
        }
        if (k == n) {
            int maxi = INT_MIN;
            for (int i = 0; i < n; i++) {
                maxi = max(maxi, nums[i]);
            }
            return maxi;
        }

        unordered_map<int, int> count;
        for (int x : nums)
            count[x]++;

        int maxi = -1;
        if (count[nums[0]] == 1)
            maxi = max(maxi, nums[0]);
        if (count[nums[n - 1]] == 1)
            maxi = max(maxi, nums[n - 1]);

        return maxi;
    }
};