class Solution {
    bool is_sufficient(vector<int> &nums,long long capacity, int k){
        long long sum=0;
        int cnt=1;
        
        for(auto& it:nums){
            if(sum+it<=capacity){
                sum+=it;
            }else{
                cnt++;
                sum=it;
            }
        }
        return cnt<=k;
    }
  
public:
    int splitArray(vector<int>& nums, int k) {
        if (nums.size() < k) return -1;
        long long low=*max_element(nums.begin(),nums.end());
        long long high=0;
        for(auto& it:nums){
            high+=it;
        }
        
        int ans=-1;
        
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(is_sufficient(nums,mid,k)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
            
        }
        return ans;
    }
};