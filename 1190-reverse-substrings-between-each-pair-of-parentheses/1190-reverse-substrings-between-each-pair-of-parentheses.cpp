class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        string result;
        for (char currentChar : s) {
            if (currentChar == '(') {
                st.push(result.length());
            } else if (currentChar == ')') {
                int start = st.top();
                st.pop();
                reverse(result.begin() + start, result.end());
            } else {
                result += currentChar;
            }
        }
        return result;
    }
};