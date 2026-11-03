class Solution {
    void find(vector<int>& nums, int ind, int curr, int& maxi, int& ans) {
        if (ind == nums.size()) {
            if (curr == maxi) {
                ans++;
                
            }
            return;
        }

        find(nums,ind+1,curr|nums[ind],maxi,ans);
        find(nums,ind+1,curr,maxi,ans);
    }

public:
    int countMaxOrSubsets(vector<int>& nums) {
        int curr = 0;
        int ans;
        int maxi = 0;

        for (int num : nums) {
            maxi |= num;
        }

        find(nums,0, curr, maxi, ans);

        return ans;
    }
};