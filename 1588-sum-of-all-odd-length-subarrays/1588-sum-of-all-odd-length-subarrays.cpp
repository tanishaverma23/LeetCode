class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum=0;
        vector<int> pref(arr.size());
        pref[0] = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            pref[i] = pref[i - 1] + arr[i];
        }

        for (int i = 0; i < arr.size(); i++) {
            for (int j = i ; j < arr.size(); j++) {
                if ((j-i+1) % 2 != 0) {
                    sum += (pref[j]-(i > 0 ? pref[i - 1] : 0));
                }
            }
        }
        return sum;
    }
};