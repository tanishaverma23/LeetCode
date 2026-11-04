class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        int m = n - x + 1;
        vector<long long> cost(m, 0);
        
        multiset<int> left_half, right_half;
        long long left_sum = 0, right_sum = 0;

        auto balance = [&]() {
            while (left_half.size() > right_half.size() + 1) {
                int val = *left_half.rbegin();
                left_half.erase(prev(left_half.end()));
                left_sum -= val;
                right_half.insert(val);
                right_sum += val;
            }
            while (right_half.size() > left_half.size()) {
                int val = *right_half.begin();
                right_half.erase(right_half.begin());
                right_sum -= val;
                left_half.insert(val);
                left_sum += val;
            }
        };

        auto insert_val = [&](int val) {
            if (left_half.empty() || val <= *left_half.rbegin()) {
                left_half.insert(val);
                left_sum += val;
            } else {
                right_half.insert(val);
                right_sum += val;
            }
            balance();
        };

        auto remove_val = [&](int val) {
            if (left_half.find(val) != left_half.end()) {
                left_half.erase(left_half.find(val));
                left_sum -= val;
            } else if (right_half.find(val) != right_half.end()) {
                right_half.erase(right_half.find(val));
                right_sum -= val;
            }
            balance();
        };

        for (int i = 0; i < x; ++i) {
            insert_val(nums[i]);
        }

        for (int i = 0; i <= m - 1; ++i) {
            long long median = *left_half.rbegin();
            cost[i] = (median * left_half.size() - left_sum) + (right_sum - median * right_half.size());

            if (i + x < n) {
                remove_val(nums[i]);
                insert_val(nums[i + x]);
            }
        }

       
        vector<long long> prev_dp(n + 1, 1e18);
        vector<long long> curr_dp(n + 1, 1e18);

        prev_dp[0] = 0;

        for (int j = 1; j <= k; ++j) {
            fill(curr_dp.begin(), curr_dp.end(), 1e18);
            long long best_prev = 1e18;
            for (int i = 1; i <= n; ++i) {
                curr_dp[i] = curr_dp[i - 1];
                if (i >= x) {
                    best_prev = min(best_prev, prev_dp[i - x]);
                    if (best_prev != 1e18) {
                        curr_dp[i] = min(curr_dp[i], best_prev + cost[i - x]);
                    }
                }
            }
            prev_dp = curr_dp;
        }

        return prev_dp[n];
    }
};