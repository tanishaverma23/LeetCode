class Solution {
    void help(vector<int>& nums, int ind, set<vector<int>>& st,
              vector<int>& curr) {

        if (ind == nums.size()) {
            vector<int> temp = curr;
            sort(temp.begin(), temp.end());
            st.insert(temp);
            return;
        }

        curr.push_back(nums[ind]);
        help(nums, ind + 1, st, curr);

        curr.pop_back();
        help(nums, ind + 1, st, curr);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curr;
        set<vector<int>> st;
        sort(nums.begin(), nums.end());
        help(nums, 0, st, curr);

        vector<vector<int>> ans(st.begin(), st.end());

        return ans;
    }
};