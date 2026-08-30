class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minInd = -1;
        int maxInd = -1;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        int n = nums.size();
        if (n == 1) {
            return 1;
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] > maxi) {
                maxi = nums[i];
                maxInd = i;
            }
            if (nums[i] < mini) {
                mini = nums[i];
                minInd = i;
            }
        }
        int leftmin = minInd + 1;
        int rightmin = n - minInd;

        int leftmax = maxInd + 1;
        int rightmax = n - maxInd;

        return min({max(leftmin, leftmax), max(rightmin, rightmax),
                    leftmin + rightmax, leftmax + rightmin});
    }
};