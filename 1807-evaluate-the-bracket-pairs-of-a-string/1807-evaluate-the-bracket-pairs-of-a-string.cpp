class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> dict;
        for (const auto& pair : knowledge) {
            dict[pair[0]] = pair[1];
        }

        string ans = "";
        string key = "";
        bool brace = false;

        for (char c : s) {
            if (c == '(') {
                brace = true;
            } else if (c == ')') {
                brace = false;
                if (dict.count(key)) {
                    ans += dict[key];
                } else {
                    ans += "?";
                }
                key = ""; 
            } else {
                if (brace) {
                    key += c; 
                } else {
                    ans += c; 
                }
            }
        }

        return ans;
    }
};