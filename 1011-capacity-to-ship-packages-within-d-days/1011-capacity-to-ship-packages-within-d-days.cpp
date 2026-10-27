class Solution {
    bool is_sufficient(vector<int>& weights, int capacity, int days) {
        int d = 0;
        int i = 0;
        int n = weights.size();
        while (i < n) {
            long long total = 0;
            while (i < n && total + weights[i] <= capacity) {
                total += weights[i];
                i++;
            }
         
            d++;
        }


        return d<=days;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = 0;
        for (auto& weight : weights) {
            high += weight;
        }

        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (is_sufficient(weights, mid, days)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};