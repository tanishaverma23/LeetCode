class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> l(26, INT_MAX), r(26, INT_MIN);
        
        // Step 1: Find the first and last occurrence of each character
        for (int i = 0; i < n; ++i) {
            int ch = s[i] - 'a';
            l[ch] = min(l[ch], i);
            r[ch] = max(r[ch], i);
        }
        
        // Step 2: Find all valid intervals [left, right]
        vector<pair<int, int>> intervals;
        for (int i = 0; i < 26; ++i) {
            if (l[i] == INT_MAX) continue;
            
            int left = l[i];
            int right = r[i];
            bool valid = true;
            
            for (int j = left; j <= right; ++j) {
                int ch = s[j] - 'a';
                if (l[ch] < left) {
                    valid = false;
                    break; // Extends before the start of our candidate interval
                }
                right = max(right, r[ch]);
            }
            
            if (valid) {
                intervals.push_back({right, left}); // Store end position first for easy greedy sorting
            }
        }
        
        // Step 3: Sort intervals by end position to greedily select non-overlapping intervals
        sort(intervals.begin(), intervals.end());
        
        vector<string> ans;
        int last_end = -1;
        for (auto& interval : intervals) {
            int right = interval.first;
            int left = interval.second;
            
            if (left > last_end) {
                ans.push_back(s.substr(left, right - left + 1));
                last_end = right;
            }
        }
        
        return ans;
    }
};