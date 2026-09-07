class Solution {
public:
    int distinctSubseqII(string s) {
        long last[26] = {0};
        long MOD = 1e9 + 7;
        
        for (char c : s) {
            long total = 0;
            for (int i = 0; i < 26; ++i) {
                total = (total + last[i]) % MOD;
            }
            last[c - 'a'] = (total + 1) % MOD;
        }
        
        long ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans = (ans + last[i]) % MOD;
        }
        
        return ans;
    }
};