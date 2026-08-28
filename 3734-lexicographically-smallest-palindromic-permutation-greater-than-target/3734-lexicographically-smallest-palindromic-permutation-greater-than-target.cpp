class Solution {
public:

    string makePalindrome(string left, char mid) {
        string right = left;
        reverse(right.begin(), right.end());

        return left + (mid == '#' ? "" : string(1, mid)) + right;
    }

    string lexPalindromicPermutation(string s, string target) {

        int n = s.size();

        // Count frequency of each character
        vector<int> cnt(26, 0);

        for (char c : s) {
            cnt[c - 'a']++;
        }

        // A palindrome can have at most one odd frequency
        int odd = 0;
        char mid = '#';

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                mid = char('a' + i);
            }
        }

        if (odd > 1) {
            return "";
        }

        // Characters available for the left half
        vector<int> half(26);

        for (int i = 0; i < 26; i++) {
            half[i] = cnt[i] / 2;
        }

        int halfLen = n / 2;

        string left = "";

        // Build the left half greedily
        for (int pos = 0; pos < halfLen; pos++) {

            bool found = false;

            // Try characters from smallest to largest
            for (int c = 0; c < 26; c++) {

                if (half[c] == 0)
                    continue;

                // Temporarily choose this character
                left.push_back(char('a' + c));
                half[c]--;

                // Build the largest possible remaining left half
                string largest = left;

                for (int x = 25; x >= 0; x--) {
                    largest += string(half[x], char('a' + x));
                }

                // Construct the largest palindrome possible
                string candidate = makePalindrome(largest, mid);

                // If even the largest completion is > target,
                // this character can be used.
                if (candidate > target) {
                    found = true;
                    break;
                }

                // Otherwise undo the choice
                left.pop_back();
                half[c]++;
            }

            // No character can make a valid answer
            if (!found) {
                return "";
            }
        }

        // Construct the final answer
        string ans = makePalindrome(left, mid);

        // IMPORTANT:
        // Answer must be STRICTLY greater than target
        if (ans > target) {
            return ans;
        }

        return "";
    }
};