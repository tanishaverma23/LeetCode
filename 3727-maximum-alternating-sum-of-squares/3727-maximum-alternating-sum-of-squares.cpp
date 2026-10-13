class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        int half = 0;
        long long first = 0;
        long long second = 0;
        if (n % 2 == 0) {
            half = n / 2;
        } else {
            half = (n / 2) + 1;
        }
        for (int i = 0; i < n; i++) {
            nums[i] = nums[i] * nums[i];
        }

        sort(nums.begin(), nums.end());
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (half == 0) {
                first += nums[i];
            } else {
                second += nums[i];
                half--;
            }
        }
        return second - first;
    }
};