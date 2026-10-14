class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (num == 1 && sum > 9)
            return "";
        if (sum > num * 9 || sum < 1)
            return "";
        int cnt = num;
        int target = sum;
        string ans = "";
        while (cnt) {
            int d = min(9, target);
            ans += to_string(d);
            target -= d;
            cnt--;
        }
        
        return ans;
    }
};