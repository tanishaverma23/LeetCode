class Solution {
public:

    bool possible(long long x, int k, vector<int>& coins) {

        int n = coins.size();

        long long total = 0;

        // Generate all subsets of coins
        for (int mask = 1; mask < (1 << n); mask++) {

            long long l = 1;
            int cnt = 0;

            // Find which coins are present in this subset
            for (int i = 0; i < n; i++) {

                if (mask & (1 << i)) {

                    l = lcm(l, (long long)coins[i]);
                    cnt++;

                    // LCM has already become too large
                    if (l > x)
                        break;
                }
            }

            if (l > x)
                continue;

            // Odd number of coins -> add
            if (cnt % 2 == 1)
                total += x / l;

            // Even number of coins -> subtract
            else
                total -= x / l;
        }

        return total >= k;
    }

    long long findKthSmallest(vector<int>& coins, int k) {

        long long left = 1;
        long long right = 1e11;

        while (left < right) {

            long long mid = left + (right - left) / 2;

            if (possible(mid, k, coins))
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};