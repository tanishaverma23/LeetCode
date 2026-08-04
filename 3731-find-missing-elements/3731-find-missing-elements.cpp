class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            mini=min(nums[i],mini);
            maxi=max(nums[i],maxi);
        }

        for(int i=mini;i<=maxi;i++){
            if(find(nums.begin(),nums.end(),i)!=end(nums)){
                     continue;
            }
            else{
                ans.push_back(i);
            }
        }
        return ans;
    }
};