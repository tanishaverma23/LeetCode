class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int ind = n - 1;

        for (int j = 1; j < n; j++) {
            if (nums[j] != nums[j - 1] + 1) {
                ind = j - 1;
                break;
            }
        }
        int sum = 0;
        for (int i = 0; i <= ind; i++) {
            sum += nums[i];
        }
        unordered_set<int> st(nums.begin(), nums.end());

        while (st.count(sum)) {
            sum++;
        }

        return sum;
    }
};