class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> totalDistinct(nums.begin(), nums.end());

        int k = totalDistinct.size();

        int left = 0;
        int ans = 0;
        unordered_map<int, int> win;
        for (int right = 0; right < n; right++) {
            win[nums[right]]++;

            while (win.size() == k) {
                ans += (n - right);
                win[nums[left]]--;
                if (win[nums[left]] == 0) {
                    win.erase(nums[left]);
                }
                left++;
            }
        }
        return ans;
    }
};