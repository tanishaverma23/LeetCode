#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        set<string> resultSet = parse(expression);
        return vector<string>(resultSet.begin(), resultSet.end());
    }

private:
    set<string> parse(const string& s) {
        set<string> result;
        int level = 0;
        int start = 0;
        vector<string> parts;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '{') level++;
            else if (s[i] == '}') level--;
            else if (s[i] == ',' && level == 0) {
                parts.push_back(s.substr(start, i - start));
                start = i + 1;
            }
        }
        parts.push_back(s.substr(start));

        if (parts.size() > 1) {
            for (const auto& part : parts) {
                set<string> res = parse(part);
                result.insert(res.begin(), res.end());
            }
            return result;
        }

        vector<set<string>> factors;
        int i = 0;
        int n = s.length();

        while (i < n) {
            if (s[i] == '{') {
                int braceCount = 1;
                int j = i + 1;
                while (j < n && braceCount > 0) {
                    if (s[j] == '{') braceCount++;
                    if (s[j] == '}') braceCount--;
                    j++;
                }
                factors.push_back(parse(s.substr(i + 1, j - i - 2)));
                i = j;
            } else if (isalpha(s[i])) {
                factors.push_back({string(1, s[i])});
                i++;
            }
        }

        result = {""};
        for (const auto& factor : factors) {
            set<string> temp;
            for (const auto& base : result) {
                for (const auto& str : factor) {
                    temp.insert(base + str);
                }
            }
            result = move(temp);
        }

        return result;
    }
};