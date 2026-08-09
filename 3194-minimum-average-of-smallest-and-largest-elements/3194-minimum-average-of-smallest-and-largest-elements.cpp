class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        vector<double>ans;
        sort(nums.begin(),nums.end());

        int i=0;
        int j=nums.size()-1;
        while(i<j){
            double avg= (nums[i] +nums[j])/2.0;
            ans.push_back(avg);
            i++;
            j--;
        }
        double mini=DBL_MAX;
        for(int i=0;i<ans.size();i++){
            mini=min(mini,ans[i]);
        }
       return mini;
    }
};