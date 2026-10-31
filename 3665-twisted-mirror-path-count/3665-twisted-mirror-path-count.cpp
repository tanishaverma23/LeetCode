class Solution {
    const long long MOD = 1e9 + 7;
    vector<vector<vector<long long>>> dp; 

    long long dfs(int r, int c, int dir, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (r < 0 || c < 0 || r >= m || c >= n) 
            return 0;

        if (r == m - 1 && c == n - 1) 
            return 1;

        if (dp[r][c][dir] != -1) 
            return dp[r][c][dir];

        int curr_r = r, curr_c = c, curr_dir = dir;
        while (curr_r >= 0 && curr_r < m && curr_c >= 0 && curr_c < n && grid[curr_r][curr_c] == 1) {
            if (curr_dir == 0) {
                curr_dir = 1; 
                curr_r++; 
            } else {
                curr_dir = 0; 
                curr_c++; 
            }
        }

        if (curr_r < 0 || curr_r >= m || curr_c < 0 || curr_c >= n) 
            return 0;
        if (curr_r == m - 1 && curr_c == n - 1) 
            return 1;

        long long right = dfs(curr_r, curr_c + 1, 0, grid);
        long long down = dfs(curr_r + 1, curr_c, 1, grid);

        return dp[r][c][dir] = (right + down) % MOD; 
    }

public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();


        dp.assign(m, vector<vector<long long>>(n, vector<long long>(2, -1)));

        long long ans = 0;
        ans = (ans + dfs(0, 1, 0, grid)) % MOD;
        ans = (ans + dfs(1, 0, 1, grid)) % MOD;

        return ans;
    }
};