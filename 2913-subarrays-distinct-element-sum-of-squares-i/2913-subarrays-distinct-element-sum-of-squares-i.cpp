class Solution {

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            set<int> op;
            for (int j = i; j < n; j++) {

                op.insert(nums[j]);

                int dis = op.size();
                ans += dis * dis;
            }
        }
        return ans;
    }
};