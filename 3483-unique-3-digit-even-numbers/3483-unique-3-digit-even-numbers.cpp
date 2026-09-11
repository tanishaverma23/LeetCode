#include <vector>

class Solution {
public:
    int totalNumbers(std::vector<int>& digits) {
        int available[10] = {0};
        for (int d : digits) {
            available[d]++;
        }

        int count = 0;

        for (int num = 100; num <= 998; num += 2) {
            int d1 = num / 100;
            int d2 = (num / 10) % 10;
            int d3 = num % 10;

            int required[10] = {0};
            required[d1]++;
            required[d2]++;
            required[d3]++;

            bool valid = true;
            for (int i = 0; i < 10; ++i) {
                if (required[i] > available[i]) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                count++;
            }
        }

        return count;
    }
};