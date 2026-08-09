class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        vector<int>res;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0;
        int j=1;
        while(i<n && j<n){
           res.push_back(nums[j]);
           res.push_back(nums[i]);
           j+=2;
           i+=2;
        }
        return res;
    }
};