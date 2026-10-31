class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n);
        pref[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + nums[i];
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int start = max(0, i - nums[i]);
            if (start == 0) {
                ans += pref[i];

            } else {
                ans = ans + pref[i]-pref[start-1];
            }
        }
        return ans;
    }
};