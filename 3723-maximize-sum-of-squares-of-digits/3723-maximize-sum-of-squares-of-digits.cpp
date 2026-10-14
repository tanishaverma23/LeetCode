class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(num==1 && sum>9)return "";
        if(sum > num * 9 || sum < 1) return "";
        int cnt = num;
        int target = sum;
        vector<int> op;
        string ans = "";
        while (cnt) {
           int d = min(9, target);
            op.push_back(d);
            target -= d;
            cnt--;
        }
        for(int num:op){
            ans+=to_string(num);
        }
        return ans;
    }
};