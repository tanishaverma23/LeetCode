class Solution {
public:
    int MOD = 1e9+7;
    long long comb[1001][1001];

    long long solve(vector<int>& nums) {
        int n = nums.size();

        if (n <= 2) return 1;

        vector<int> left, right;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[0])
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }

        long long ways = comb[n - 1][left.size()];

        ways = (ways * solve(left)) % MOD;
        ways = (ways * solve(right)) % MOD;

        return ways;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i)
                    comb[i][j] = 1;
                else
                    comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % MOD;
            }
        }

        return (solve(nums) - 1 + MOD) % MOD;
    }
};