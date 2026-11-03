class Solution {
    bool help(vector<int>& nums,int ind,int curr,int rem,vector<vector<int>>&dp){
        if(ind==nums.size()){
            if(curr==rem){
                return 1;
            }
            return 0;
        }

        if(dp[ind][curr]!=-1){
            return dp[ind][curr];
        }

        bool Pick=help(nums,ind+1,curr+nums[ind],rem-nums[ind],dp);
        bool notPick=help(nums,ind+1,curr,rem,dp);

        return dp[ind][curr]=(Pick||notPick);
    }
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int curr=0;
        int rem=0;
        for(auto& num:nums){
            rem+=num;
        }

        if(rem % 2 != 0) return false;

        vector<vector<int>>dp(n,vector<int>(rem+1,-1));

        return help(nums,0,curr,rem,dp);
        
    }
};