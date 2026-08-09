class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<vector<int>> ans;
        vector<vector<int>> temp(n + 1);
        for (int i = 0; i < n; i++) {
            int size = groupSizes[i];
            temp[size].push_back(i);

            if (temp[size].size() == size) {
                ans.push_back(temp[size]);
                temp[size].clear();
            }
        }

        return ans;
    }
};