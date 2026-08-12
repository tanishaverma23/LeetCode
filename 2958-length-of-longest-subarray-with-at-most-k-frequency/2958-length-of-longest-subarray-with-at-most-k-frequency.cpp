class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MIN;
        int i = 0;
        unordered_map<int, int> freq;
        for (int j = i; j < n; j++) {

            freq[nums[j]]++;

            while (freq[nums[j]] > k) {
                freq[nums[i]]--;
                i++;
            }

            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};