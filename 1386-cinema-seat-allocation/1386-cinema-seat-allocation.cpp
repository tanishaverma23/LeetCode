class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, set<int>> mp;

        for (auto &seat : reservedSeats) {
            mp[seat[0]].insert(seat[1]);
        }

        int ans = (n - mp.size()) * 2;

        for (auto &row : mp) {
            int r = row.first;
            set<int> &s = row.second;

            bool left = true;
            bool middle = true;
            bool right = true;

            // Seats 2,3,4,5
            for (int i = 2; i <= 5; i++) {
                if (s.count(i)) {
                    left = false;
                }
            }

            // Seats 4,5,6,7
            for (int i = 4; i <= 7; i++) {
                if (s.count(i)) {
                    middle = false;
                }
            }

            // Seats 6,7,8,9
            for (int i = 6; i <= 9; i++) {
                if (s.count(i)) {
                    right = false;
                }
            }

            if (left && right)
                ans += 2;
            else if (left || middle || right)
                ans += 1;
        }

        return ans;
    }
};