class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int ratio = 0;
        vector<int> prefEven(nums.size(), 0);
        vector<int> prefOdd(nums.size(), 0);

        prefEven[0] = (nums[0] % 2 == 0);
        prefOdd[0] = (nums[0] % 2 == 1);
  
        for (int j = 1; j < nums.size(); j++) {

            prefEven[j] = prefEven[j - 1] + (nums[j] % 2 == 0);
            prefOdd[j] = prefOdd[j - 1] + (nums[j] % 2 == 1);
        }

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {

                int even = prefEven[j] - (i ? prefEven[i - 1] : 0);
                int odd = prefOdd[j] - (i ? prefOdd[i - 1] : 0);

                if ((odd > 0) && (even * b <= odd * a)) {
                    ratio++;
                }
            }
        }
        return ratio;
    }
};