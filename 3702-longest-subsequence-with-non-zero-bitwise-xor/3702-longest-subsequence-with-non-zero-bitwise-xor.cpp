class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        int r = 1;
        int totalXor = nums[0];
        while (r < n) {
            totalXor = totalXor ^ nums[r];
            r++;
        }
        if (totalXor != 0) {
            return n;
        }
        bool swi = true;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swi = false;
                break;
            }
        }
        if (swi)
            return 0;

        return n - 1;
    }
};
