class Solution {
private:
    void helper(vector<int>&nums,int k,int ind,int n,int sum,vector<int>&output,vector<vector<int>>&res){
        if(output.size()==k){
            if(sum==n){
                res.push_back(output);
                return;
            }
        }
        if (ind >= nums.size() || sum > n) {
            return;
        }
        output.push_back(nums[ind]);
        helper(nums, k, ind + 1, n, sum + nums[ind], output, res);
        output.pop_back();
        helper(nums, k, ind + 1, n, sum, output, res);
          
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>nums={1,2,3,4,5,6,7,8,9};
        vector<int>output;
        vector<vector<int>>res;
        int sum=0;
        int ind=0;
        helper(nums,k,ind,n,sum,output,res);
        return res;
        
    }
};
