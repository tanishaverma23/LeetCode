class Solution {
public:
    string digitSum(string s, int k) {
        while (s.length() > k) {
            string nextStr = "";
            for (int i = 0; i < s.length(); i += k) {
                int groupSum = 0;
                for (int j = i; j < min((int)s.length(), i + k); j++) {
                    groupSum += s[j] - '0';
                }
                nextStr += to_string(groupSum);
            }
            s = nextStr;
        }
        return s;
    }
};