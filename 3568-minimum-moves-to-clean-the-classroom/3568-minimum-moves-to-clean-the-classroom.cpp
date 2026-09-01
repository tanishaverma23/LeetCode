class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {

        int m = classroom.size();
        int n = classroom[0].size();

        // litterIndex[i][j] tells us which bit
        // belongs to litter at (i,j)
        vector<vector<int>> litterIndex(
            m, vector<int>(n, -1)
        );

        int sr = 0, sc = 0;
        int litterCount = 0;

        // Find starting position and number/index of litter
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                else if (classroom[i][j] == 'L') {
                    litterIndex[i][j] = litterCount++;
                }
            }
        }

        // No litter
        if (litterCount == 0)
            return 0;

        // Initially every litter is uncollected.
        // Example: 3 litter -> 111
        int fullMask = (1 << litterCount) - 1;

        // visited[row][col][energy][mask]
        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << litterCount, false)
                )
            )
        );

        queue<tuple<int, int, int, int>> q;

        // row, col, remaining energy, mask
        q.push({sr, sc, energy, fullMask});

        visited[sr][sc][energy][fullMask] = true;

        int moves = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                auto [r, c, currEnergy, mask] = q.front();
                q.pop();

                // All litter collected
                if (mask == 0)
                    return moves;

                // Can't move if energy is zero
                if (currEnergy == 0)
                    continue;

                for (int k = 0; k < 4; k++) {

                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    // Outside grid
                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n)
                        continue;

                    // Obstacle
                    if (classroom[nr][nc] == 'X')
                        continue;

                    int newEnergy;

                    // Reset area
                    if (classroom[nr][nc] == 'R')
                        newEnergy = energy;
                    else
                        newEnergy = currEnergy - 1;

                    int newMask = mask;

                    // Litter
                    if (classroom[nr][nc] == 'L') {

                        int index = litterIndex[nr][nc];

                        newMask &= ~(1 << index);
                    }

                    // New state
                    if (!visited[nr][nc][newEnergy][newMask]) {

                        visited[nr][nc][newEnergy][newMask] = true;

                        q.push({
                            nr,
                            nc,
                            newEnergy,
                            newMask
                        });
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};