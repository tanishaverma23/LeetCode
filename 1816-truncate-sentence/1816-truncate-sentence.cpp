class Solution {
public:
    string truncateSentence(string s, int k) {
        string ans;
        int len = s.length();
        int cnt = k;
        int i = 0;
        while (i < len && k != 0) {

            if (s[i] == ' ') {

                k--;
            }

            if (k == 0) {
                break;
            }

            ans += s[i];
            i++;
        }

        return ans;
    }
};
