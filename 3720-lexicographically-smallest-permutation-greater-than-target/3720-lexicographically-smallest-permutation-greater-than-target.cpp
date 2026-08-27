class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        vector<int> freq(26);

        for (char c : s) {
            freq[c - 'a']++;
        }

        string prefix = "";

        int i = 0;

        // Match target as much as possible
        while (i < n) {

            int x = target[i] - 'a';

            if (freq[x] > 0) {
                freq[x]--;
                prefix += target[i];
                i++;
            }
            else {
                break;
            }
        }

        // Try to make the answer greater
        // starting from the current position and backtracking
        while (i >= 0) {

            if (i < n) {
                int x = target[i] - 'a';

                // Try smallest character greater than target[i]
                for (int c = x + 1; c < 26; c++) {

                    if (freq[c] > 0) {

                        string ans = prefix + char('a' + c);

                        freq[c]--;

                        // Add remaining characters in sorted order
                        for (int j = 0; j < 26; j++) {
                            ans += string(freq[j], 'a' + j);
                        }

                        return ans;
                    }
                }
            }

            // Backtrack one position
            if (i == 0)
                break;

            i--;

            // Restore the character we matched at position i
            freq[target[i] - 'a']++;

            prefix.pop_back();
        }

        return "";
    }
};