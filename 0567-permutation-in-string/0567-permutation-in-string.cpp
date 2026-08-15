class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length())
                   return false;
        vector<int> freq(26, 0);
        for (int i = 0; i < s1.length(); i++) {
            freq[s1[i] - 'a']++;
        }
        int k = s1.size();

        for (int l = 0; l <= s2.length() - k; l++) {
            vector<int> temp(freq.begin(), freq.end());
            int cnt = k;
            int r = l;
            while (cnt>0 && temp[s2[r] - 'a'] > 0) {
                temp[s2[r] - 'a']--;
                cnt--;
                r++;
            }
            if (cnt== 0) {
                return true;
            }
           
            
          
        }
        return false;
    }
};