class Solution {
    int solve(vector<int>& stoneValue, int i, int n, vector<int>& dp) {

        if (i >= n)
            return 0;

        if (dp[i]!=INT_MIN)return dp[i];
            int ans = INT_MIN;
        int sum = 0;

        for (int k = 0; k <= 2; k++) {
            if (i + k >= n)
                break;

            sum += stoneValue[i + k];
            ans = max(ans, sum - solve(stoneValue, i + k + 1, n, dp));
        }
        return dp[i]= ans;
    }

public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n,INT_MIN);
        int ans = solve(stoneValue, 0, n, dp);

        if (ans > 0) {
            return "Alice";
        } else if (ans < 0) {
            return "Bob";
        }
        return "Tie";
    }
};