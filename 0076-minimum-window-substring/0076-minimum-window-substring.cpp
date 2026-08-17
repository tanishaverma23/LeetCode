class Solution {
public:
    string minWindow(string s, string t) {

        vector<int> freq(52, 0);
        vector<int> wind(52, 0);

        for (char c : t) {
            if (c >= 'a' && c <= 'z')
                freq[c - 'a']++;
            else
                freq[c - 'A' + 26]++;
        }

        int left = 0;
        int required = t.length();
        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.length(); right++) {

            int index;

            if (s[right] >= 'a' && s[right] <= 'z')
                index = s[right] - 'a';
            else
                index = s[right] - 'A' + 26;

            wind[index]++;

            if (wind[index] <= freq[index])
                required--;

            while (required == 0) {

                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                if (s[left] >= 'a' && s[left] <= 'z')
                    index = s[left] - 'a';
                else
                    index = s[left] - 'A' + 26;

                wind[index]--;

                if (wind[index] < freq[index])
                    required++;

                left++;
            }
        }

        if (minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};