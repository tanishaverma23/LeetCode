class Solution {
    int helper(vector<int>&piles,vector<vector<int>>& dp,int i,int j){
        if(i==j){
            return piles[i];
        } 
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int left= piles[i]-helper(piles,dp,i+1,j);
        int right=piles[j]-helper(piles,dp,i,j-1);

        return dp[i][j]=max(left,right);
    }
public:
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return helper(piles,dp,0,piles.size()-1)>=0;
        
    }
};