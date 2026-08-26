class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int left = 0;
        int cnt = 0;
        string ans = "";

        for (int right = 0; right < s.length(); right++) {

            if (s[right] == '1')
                cnt++;

            while (cnt == k) {

                string curr = s.substr(left, right - left + 1);

                if (ans.empty() || curr.length() < ans.length() ||
                    (curr.length() == ans.length() && curr < ans)) {
                    ans = curr;
                }

                if (s[left] == '1')
                    cnt--;

                left++;
            }
        }

        return ans;
    }
};