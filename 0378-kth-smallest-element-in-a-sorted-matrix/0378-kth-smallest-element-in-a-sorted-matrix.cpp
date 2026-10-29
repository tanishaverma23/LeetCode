class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();

        int low = matrix[0][0];
        int high = matrix[n - 1][m - 1];

        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int cnt = 0;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (matrix[i][j] <= mid) {
                        cnt++;
                    }
                }
            }

            if (cnt >= k) {
                ans = mid;
                high = mid - 1;
            } else {

                low = mid + 1;
            }
        }
        return ans;
    }
};