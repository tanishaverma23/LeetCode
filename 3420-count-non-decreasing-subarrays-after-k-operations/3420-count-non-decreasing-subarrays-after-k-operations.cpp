class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        long long ops = 0;
        deque<pair<int, int>> dq;
        int r = n - 1;

        for (int l = n - 1; l >= 0; --l) {
            int count = 1;
            while (!dq.empty() && dq.front().first < nums[l]) {
                ops += 1LL * (nums[l] - dq.front().first) * dq.front().second;
                count += dq.front().second;
                dq.pop_front();
            }
            dq.push_front({nums[l], count});

            while (ops > k) {
                ops -= dq.back().first - nums[r];
                dq.back().second--;
                if (dq.back().second == 0) {
                    dq.pop_back();
                }
                r--;
            }

            ans += r - l + 1;
        }

        return ans;
    }
};