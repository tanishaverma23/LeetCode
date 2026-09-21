class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            vector<long long> next_dp(k, 0);
            int mod = num % k;
            
            next_dp[mod]++;

            for (int r = 0; r < k; ++r) {
                if (dp[r] > 0) {
                    int next_mod = (r * mod) % k;
                    next_dp[next_mod] += dp[r];
                }
            }

            for (int r = 0; r < k; ++r) {
                result[r] += next_dp[r];
            }

            dp = move(next_dp);
        }

        return result;
    }
};