class Solution {
    void generate(int ind,vector<int>&nums,vector<vector<int>>&ans, vector<int>&curr){
        if(ind==nums.size()){
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[ind]);
        generate(ind+1,nums,ans,curr);

        curr.pop_back();
        generate(ind+1,nums,ans,curr);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>curr;
        generate(0,nums,ans,curr);

        return ans;
    }
};