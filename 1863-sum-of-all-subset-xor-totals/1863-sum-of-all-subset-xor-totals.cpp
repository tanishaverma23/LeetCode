class Solution {
    void helper(vector<int>&nums , int ind , int curr , int& total){
        if(ind==nums.size()){
            total+=curr;
            return;
        }

        helper(nums,ind+1,curr^nums[ind],total);
        helper(nums,ind+1,curr,total);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        int total=0;
        int curr=0;
        
        helper(nums,0,curr,total);

        return total;
    }
};