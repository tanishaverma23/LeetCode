class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {

        int n = stoneValue.size();

        // prefix[i] = sum of elements from 0 to i-1
        // This helps us calculate range sums in O(1)
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        // dp[l][r] = maximum score Alice can get
        // from the subarray [l ... r]
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // length = size of current subarray
        for (int len = 2; len <= n; len++) {

            for (int l = 0; l + len - 1 < n; l++) {

                int r = l + len - 1;

                // Try every possible splitting point
                for (int k = l; k < r; k++) {

                    // Sum of left part [l ... k]
                    int leftSum = prefix[k + 1] - prefix[l];

                    // Sum of right part [k+1 ... r]
                    int rightSum = prefix[r + 1] - prefix[k + 1];

                    if (leftSum < rightSum) {

                        // Alice can only take the LEFT part.
                        // Then Bob continues with the right part.
                        dp[l][r] = max(
                            dp[l][r],
                            leftSum + dp[l][k]
                        );

                    }
                    else if (rightSum < leftSum) {

                        // Alice can only take the RIGHT part.
                        dp[l][r] = max(
                            dp[l][r],
                            rightSum + dp[k + 1][r]
                        );

                    }
                    else {

                        // Both sums are equal.
                        // Alice can choose either side.
                        dp[l][r] = max({
                            dp[l][r],
                            leftSum + dp[l][k],
                            rightSum + dp[k + 1][r]
                        });
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};