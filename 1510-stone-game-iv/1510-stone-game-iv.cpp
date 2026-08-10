class Solution {
   
public:
    bool winnerSquareGame(int n) {
        //dp[i] = true
        //means the current player can win with i remaining.
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }

     int solve(int n,vector<int>&dp){
        if(n==0){
            return false;
        }

        if(dp[n]!=-1)return dp[n];

        for(int i=1;i*i<=n;i++){
            int square=i*i;

            if(solve(n-square,dp)==false){
            return dp[n]= true;
            }
        }
        return dp[n]=false;
    }
};