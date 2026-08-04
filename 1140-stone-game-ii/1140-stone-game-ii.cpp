class Solution {

    int solve(vector<int>& piles, vector<int>& suffix, int i, int M , int n, vector<vector<int>>& dp) {
        if (i >= n) {
            return 0;
        }

        if (i + 2 * M >= n) {
            return suffix[i];
        }

        if(dp[i][M]!=-1)return dp[i][M];

        int ans = 0;
        for (int x = 1; x <= 2 * M; x++) {
            ans = max(ans, suffix[i] - solve(piles, suffix, i + x, max(M, x),n,dp));
        }

        return dp[i][M]=ans;
    }

public:
    int stoneGameII(vector<int>& piles) {
        
        int n = piles.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        vector<int> suffix(n, 0);
        suffix[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }
        return solve(piles, suffix, 0, 1,n,dp);
    }
};