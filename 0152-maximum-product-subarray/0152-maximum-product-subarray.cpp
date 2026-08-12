class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int maxi = nums[0];
        int mini = nums[0];

        int ans = nums[0];

        for(int i = 1; i < nums.size(); i++){

            int x = nums[i];

            int tempMax = max({x, maxi * x, mini * x});
            int tempMin = min({x, maxi * x, mini * x});

            maxi = tempMax;
            mini = tempMin;

            ans = max(ans, maxi);
        }

        return ans;
    }
};