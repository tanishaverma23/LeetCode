class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m=word2.size();
        vector<int> ans;
        vector<int> last(m, -1);
       
        int j = m - 1;

        for (int i = n - 1; i >= 0; i--) {
            if (j >= 0 && word1[i] == word2[j]) {
                last[j] = i;
                j--;
            }
        }

        j = 0;
        bool can_change=true;
        for (int i = 0; i < n && j<m; i++) {
       
                if (word1[i] == word2[j] ||
                    (can_change == true && (j == m - 1 || i+1 <= last[j + 1]))) {
                    if (word1[i] != word2[j]) {
                        can_change=false;
                    }
                    ans.push_back(i);
                    j++;
                }
           }
        
        return (j == m) ? ans : vector<int>();
    }
};