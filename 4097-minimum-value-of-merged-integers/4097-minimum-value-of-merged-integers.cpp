class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;
        int i=0;
        int j=i+1;
        while(i<j && i<n && j<n ){
            
            string merged = to_string(nums[i]) + to_string(nums[j]);
            mini = min(mini, stoi(merged));
            i=i+2;
            j=i+1;
           }
        
        return mini;
    }
};