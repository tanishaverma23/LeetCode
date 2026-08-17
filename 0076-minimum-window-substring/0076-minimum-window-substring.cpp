class Solution {
public:
    string minWindow(string s, string t) {

        vector<int> freq(128, 0);
        for (char c : t) {
            freq[c]++;
        }

        int left = 0, count = t.length();
        int min_len = INT_MAX, start_idx = 0;

        for (int right = 0; right < s.length(); right++) {
            if (freq[s[right]] > 0) {
                count--;
            }
            freq[s[right]]--;

            // When all characters are matched, try shrinking the window from
            // left
            while (count == 0) {
                if (right - left + 1 < min_len) {
                    min_len = right - left + 1;
                    start_idx = left;
                }

                freq[s[left]]++;
                if (freq[s[left]] > 0) {
                    count++;
                }
                left++;
            }
        }

        return min_len == INT_MAX ? "" : s.substr(start_idx, min_len);
    }
};