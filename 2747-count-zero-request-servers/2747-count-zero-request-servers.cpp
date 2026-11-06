class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = queries.size();
        vector<int> ans(m);
        
        vector<pair<int, int>> sortedQueries(m);
        for (int i = 0; i < m; ++i) {
            sortedQueries[i] = {queries[i], i};
        }
        
        sort(sortedQueries.begin(), sortedQueries.end());
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        int left = 0, right = 0;
        int logSize = logs.size();
        unordered_map<int, int> serverCount;
        
        for (auto& q : sortedQueries) {
            int queryTime = q.first;
            int originalIndex = q.second;
            int startTime = queryTime - x;
            
      
            while (right < logSize && logs[right][1] <= queryTime) {
                serverCount[logs[right][0]]++;
                right++;
            }
            
            
            while (left < logSize && logs[left][1] < startTime) {
                serverCount[logs[left][0]]--;
                if (serverCount[logs[left][0]] == 0) {
                    serverCount.erase(logs[left][0]);
                }
                left++;
            }
            
            ans[originalIndex] = n - serverCount.size();
        }
        
        return ans;
    }
};