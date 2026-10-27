class Solution {
    bool is_sufficient(vector<int>& nums,int divisor, int threshold){
       int sum=0;
       for(auto& it:nums){
        sum+=(it+divisor-1)/divisor;

       }
       if(sum>threshold)return false;

       return true;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        
        long long ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;

            if(is_sufficient(nums,mid,threshold)){
                  ans=mid;
                  high=mid-1;
            }else{
                 low=mid+1;
            }

        }
        return ans;
    }
};