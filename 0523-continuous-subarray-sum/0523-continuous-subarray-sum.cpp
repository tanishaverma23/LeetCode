class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;

        int sum = 0; // running sum

        mp[0] = -1; // at index -1 remainder after dividing by k is 0
        for (int i = 0; i < n; i++) {

            sum += nums[i];
            int rem=sum%k;
            if(mp.count(rem)){
                if(i-mp[rem]>=2){
                    return true;
                }
            }else{
                mp[rem]=i;
            }
        }

        return false;
    }
};