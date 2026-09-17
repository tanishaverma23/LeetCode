#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int minSumOfLengths(std::vector<int>& arr, int target) {
        int n = arr.size();
        std::vector<int> min_len(n, INT_MAX);
        
        int left = 0, sum = 0;
        int min_length_so_far = INT_MAX;
        int ans = INT_MAX;

        for (int right = 0; right < n; ++right) {
            sum += arr[right];

            while (sum > target) {
                sum -= arr[left++];
            }

            if (sum == target) {
                int curr_len = right - left + 1;

                if (left > 0 && min_len[left - 1] != INT_MAX) {
                    ans = std::min(ans, curr_len + min_len[left - 1]);
                }

                min_length_so_far = std::min(min_length_so_far, curr_len);
            }

            min_len[right] = min_length_so_far;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};