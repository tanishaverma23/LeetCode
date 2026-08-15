class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int k = s1.length();

        if (k > s2.length())
            return false;

        vector<int> freq(26, 0);
        vector<int> window(26, 0);

        for (char c : s1)
            freq[c - 'a']++;

        int left = 0;

        for (int right = 0; right < s2.length() ; right++) {
            window[s2[right] - 'a']++;
            if (right - left + 1 > k) {
                window[s2[left] - 'a']--;
                left++;
            }
            if (right - left + 1 == k) {
                if (freq == window)
                    return true;
            }
         
        }

        return false;
    }
};