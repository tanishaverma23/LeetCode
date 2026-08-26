class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        set<int> st(nums.begin(), nums.end());
        vector<int> help(st.begin(), st.end());

        if (help.size() < 3) {
            int maxi = help[0];
            for (auto& i : help) {
                maxi = max(maxi, i);
            }
            return maxi;
        }
        int cnt=0;
        int ans=0;
        for(int i=help.size()-1;i>=0;i--){
            cnt++;
            if(cnt==3){
                ans=help[i];
            }

        }

       /* int first = nums[0];
        int second=;
        int third=nums[2];

        for (int i = 1; i < help.size(); i++) {
            if (nums[i] > first) {
                first = nums[i];
                second = first;
                third = second;
            } else if (nums[i] > second) {
                second = nums[i];
                third = second;

            } else if (nums[i] > third) {
                third = nums[i];
            }
        }*/
     return ans;
       
    }
};