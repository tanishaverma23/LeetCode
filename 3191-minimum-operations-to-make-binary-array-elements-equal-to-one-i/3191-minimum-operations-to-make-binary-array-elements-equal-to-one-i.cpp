class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;

        for (int right = 0; right <= n - 3; right++) {
            if (nums[right] == 0) {

                nums[right] ^= 1;
                nums[right + 1] ^= 1;
                nums[right + 2] ^= 1;
                cnt++;
            }
        }

        
        if (nums[n - 2] == 0 || nums[n - 1] == 0) {
            return -1;
        }

        return cnt;
    }
};






