#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        vector<vector<int>> A(n);
        for (int i = 0; i < n; ++i) {
            A[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }
        
        sort(A.begin(), A.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[1] != b[1]) return a[1] < b[1];
            return a[0] < b[0];
        });
        
        vector<int> R(n);
        for (int i = 0; i < n; ++i) {
            R[i] = A[i][1];
        }
        
        vector<vector<pair<long long, vector<int>>>> dp(5, vector<pair<long long, vector<int>>>(n + 1));
        
        for (int i = 1; i <= n; ++i) {
            int l = A[i - 1][0];
            int weight = A[i - 1][2];
            int orig_idx = A[i - 1][3];
            
            int prev = lower_bound(R.begin(), R.begin() + i - 1, l) - R.begin();
            
            for (int k = 1; k <= 4; ++k) {
                dp[k][i] = dp[k][i - 1];
                
                long long take_weight = dp[k - 1][prev].first + weight;
                vector<int> take_indices = dp[k - 1][prev].second;
                take_indices.push_back(orig_idx);
                sort(take_indices.begin(), take_indices.end());
                
                if (take_weight > dp[k][i].first) {
                    dp[k][i] = {take_weight, take_indices};
                } else if (take_weight == dp[k][i].first && take_weight > 0) {
                    if (take_indices < dp[k][i].second) {
                        dp[k][i] = {take_weight, take_indices};
                    }
                }
            }
        }
        
        return dp[4][n].second;
    }
};