class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        int n = nums.size();
        unordered_map<int, int> freq;
        for (auto& num : nums) {
            freq[num]++;
        }

        for (int i = 1; i <= k; i++) {
            int key=0;
            int maxi = INT_MIN;
            for (auto& it : freq) {
                if (it.second >= maxi) {
                    key=it.first;
                    maxi = it.second;
                }
            }
            freq.erase(key);
            ans.push_back(key);

        }
        return ans;
    }
};