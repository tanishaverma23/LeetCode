class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int ind = n-1;

        for (int j = 1; j < n; j++) {
            if (nums[j] != nums[j - 1] + 1) {
                ind = j - 1;
                break;
            }
        }
        int sum = 0;
        for (int i = 0; i <= ind; i++) {
            sum += nums[i];
        }
        if (find(nums.begin(), nums.end(), sum) == nums.end()) {
            return sum;
        }

        while (find(nums.begin(), nums.end(), sum) != nums.end()) {

            sum+=1;
        }
        return sum;
        }

    };