class Solution {
    void count(string s, int& cnt1, int& cnt0) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0')
                cnt0++;
            else
                cnt1++;
        }
    }

public:
    int countValidPrefixes(string s) {
        int ans = 0;

        for (int j = 0; j < s.length(); j++) {
            int cnt1 = 0;
            int cnt0 = 0;

            int len = j - 0 + 1;

            string n = s.substr(0, len);
            count(n, cnt1, cnt0);

            if (abs(cnt1 - cnt0) <= 1) {
                ans++;
            }
        }

        return ans;
    }
};