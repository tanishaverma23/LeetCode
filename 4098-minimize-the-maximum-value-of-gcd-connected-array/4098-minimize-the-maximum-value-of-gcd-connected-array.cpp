class Solution {
    int SPF(int val) {
        for (int i = 2; i * i <= val; i++) {
            if (val % i == 0) {
                return i;
            }
        }
        return val;
    }

public:
    long long minimumMaxValue(int n, int index, int value) {
        if (value == 1)
            return -1;

        long long p = SPF(value);

        if (value - p < 2 * index) {
            return -1;
        }

        long long t = n - index - 1;
        if (t == 0)
            return value;

        return (long long)value + p + 2 * (t - 1);
    }
};