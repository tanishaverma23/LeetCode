class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            vector<int> temp;
            while (num != 0) {
                int dig = num % 10;
                temp.push_back(dig);
                num = num / 10;
            }

            for (int j = temp.size() - 1; j >= 0; j--) {
                ans.push_back(temp[j]);
            }
        }
        return ans;
    }
};