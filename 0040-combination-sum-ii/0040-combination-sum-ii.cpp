class Solution {
    void help(vector<int>& candidates, int ind, int& sum, vector<int>& curr,
              vector<vector<int>>& ans, int target) {

        if (sum == target) {
            ans.push_back(curr);
            return;
        }

        if (sum > target || ind == candidates.size()) {
            return;
        }

        for (int i = ind; i < candidates.size(); i++) {
            if(candidates[i]>target)break;
            if(i>ind && candidates[i]==candidates[i-1])continue;

            curr.push_back(candidates[i]);
            sum += candidates[i];
            help(candidates, i + 1, sum, curr, ans, target);

            curr.pop_back();
            sum -= candidates[i];
            
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        int sum = 0;
        help(candidates, 0, sum, curr, ans, target);

        return ans;
    }
};