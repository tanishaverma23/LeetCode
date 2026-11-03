class Solution {
    void help(vector<int>& candidates, int ind, int& sum, vector<int>& curr,
              vector<vector<int>>&ans, int target) {
        if (sum > target || ind == candidates.size()) {
            return;
        }
        if (sum == target) {
            ans.push_back(curr);
            return;
        }

        curr.push_back(candidates[ind]);
        sum += candidates[ind];
        help(candidates, ind, sum, curr, ans, target);

        curr.pop_back();
        sum -= candidates[ind];
        help(candidates, ind + 1, sum, curr, ans, target);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        int sum = 0;
        help(candidates, 0, sum, curr, ans, target);

        return ans;
    }
};