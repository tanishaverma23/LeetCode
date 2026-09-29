class Solution {
public:
    bool hasValidPath(std::vector<std::vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if ((m + n - 1) % 2 != 0) return false;
        if (grid[0][0] == ')') return false;

        bool visited[100][100][101] = {false};
        std::queue<std::tuple<int, int, int>> q;

        q.push({0, 0, 1});
        visited[0][0][1] = true;

        int dr[] = {1, 0};
        int dc[] = {0, 1};

        while (!q.empty()) {
            auto [r, c, k] = q.front();
            q.pop();

            if (r == m - 1 && c == n - 1 && k == 0) {
                return true;
            }

            for (int i = 0; i < 2; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr < m && nc < n) {
                    int nk = k + (grid[nr][nc] == '(' ? 1 : -1);

                    if (nk >= 0 && nk <= (m + n) / 2 && !visited[nr][nc][nk]) {
                        visited[nr][nc][nk] = true;
                        q.push({nr, nc, nk});
                    }
                }
            }
        }

        return false;
    }
};