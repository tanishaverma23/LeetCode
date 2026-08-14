class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt0 = 0;
        int left = 0;
        int ans = 0;
        for (int right = 0; right < n; right++) {
            if (nums[right] == 0) {
                cnt0++;
            }

            while (cnt0 > k) {
          
                if (nums[left] == 0) {
                    cnt0--;
                }
                left++;
            }
            int len = right - left + 1;
            ans = max(ans, len);
        }
        return ans;
    }
};
