class Solution {
private:
void generateAll(string curr, int open , int close,int n, vector<string>& res) {
    if (curr.length() == 2 * n) {
       res.push_back(curr);
        return;
    }
    if(open<n)generateAll(curr + '(', open+1,close,n, res);
    if(close<open)generateAll(curr + ')',open , close+1, n, res);
}
public:
vector<string> generateParenthesis(int n) {
    vector<string> res;
    int open=0;
    int close=0;
    generateAll("",open,close, n, res);
    return res;
}
};