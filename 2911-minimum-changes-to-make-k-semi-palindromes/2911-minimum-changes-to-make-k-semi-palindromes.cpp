class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.length();
        vector<vector<int>> v(n, vector<int>(n, 1e9));
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int len = j - i + 1;
                for (int d = 1; d < len; ++d) {
                    if (len % d == 0) {
                        int changes = 0;
                        for (int rem = 0; rem < d; ++rem) {
                            int left = i + rem;
                            int right = j - (d - 1 - rem);
                            while (left < right) {
                                if (s[left] != s[right]) {
                                    changes++;
                                }
                                left += d;
                                right -= d;
                            }
                        }
                        v[i][j] = min(v[i][j], changes);
                    }
                }
            }
        }
        
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 1e9));
        for (int i = 0; i < n; ++i) {
            dp[i][1] = v[i][n - 1];
        }
        
        for (int c = 2; c <= k; ++c) {
            for (int i = 0; i < n; ++i) {
                for (int x = i + 1; x < n - 1; ++x) {
                    if (v[i][x] != 1e9 && dp[x + 1][c - 1] != 1e9) {
                        dp[i][c] = min(dp[i][c], v[i][x] + dp[x + 1][c - 1]);
                    }
                }
            }
        }
        
        return dp[0][k];
    }
};