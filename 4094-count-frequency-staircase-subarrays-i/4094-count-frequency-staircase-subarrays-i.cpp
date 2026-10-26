class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n = nums.size();
        int valid_count = 0;
        for (int i = 0; i < n; i++) {
            vector<int> distinct_order;
                unordered_map<int, int> freq;
            for (int j = i; j < n; j++) {
                
                
                    int val = nums[j];
                    if (freq[val] == 0) {
                        distinct_order.push_back(val);
                    }
                    freq[val]++;
                

                bool is_staircase = true;
                int expected_freq = 1;

                for (int val : distinct_order) {
                    if (freq[val] != expected_freq) {
                        is_staircase = false;
                        break;
                    }
                    expected_freq++;
                }
                if (is_staircase) {
                    valid_count++;
                }
            }
        }
        return valid_count;
    }
};