class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int median=0;
        sort(nums.begin(),nums.end());

        for(auto& it:nums){
           sum+=it;
        }
  
        median=nums[n/2];

        int ans=0;

        for(auto& num:nums){
            int diff=abs(median-num);
            ans+=diff;
        }

        return ans;
    }
};