class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();

        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] ^ arr[i];
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {

            for (int k = i + 1; k < n; k++) {

                if (pref[i] == pref[k + 1]) {
                    ans += (k - i);
                }
            }
        }
        return ans;
    }
};