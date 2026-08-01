class Solution {
public:
    int maximumWidth(vector<int>& planks) {

        unordered_map<long long, int> freq;
        for (int p : planks) {
            freq[p]++;
        }

        vector<pair<long long, int>> unique_planks;
        for (auto& [val, count] : freq) {
            unique_planks.push_back({val, count});
        }

        unordered_map<long long, int> possible_widths;

        for (auto& [val, count] : freq) {
            possible_widths[val] += count;
        }

        int m = unique_planks.size();
        for (int i = 0; i < m; i++) {

            long long same_sum = unique_planks[i].first * 2;
            possible_widths[same_sum] += unique_planks[i].second / 2;

            for (int j = i + 1; j < m; j++) {
                long long diff_sum =
                    unique_planks[i].first + unique_planks[j].first;
                possible_widths[diff_sum] +=
                    min(unique_planks[i].second, unique_planks[j].second);
            }
        }

        int max_width = 0;
        for (auto& [height, width] : possible_widths) {
            max_width = max(max_width, width);
        }

        return max_width;
    }
};