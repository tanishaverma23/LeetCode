class Solution {
public:
    int smallestNumber(int n, int t) {
        int ans = 0;
        for (int i = n; i <= 100; i++) {
            int num = i;
            int product = 1;
            while (num != 0) {
                int digit = num % 10;
                product *= digit;
                num = num / 10;
            }

            if (product % t == 0) {
                ans = i;
                break;
            }
        }

        return ans;
    }
};