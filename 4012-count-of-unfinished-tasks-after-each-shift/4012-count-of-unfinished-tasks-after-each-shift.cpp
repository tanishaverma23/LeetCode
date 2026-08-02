class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n = tasks.size();

   

        vector<long long> prefix(n);
        prefix[0] = tasks[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + tasks[i];
        }

        long long total = prefix[n - 1];

        vector<int> ans;
        int idx = 0;
        long long progress = 0;

        for (long long shift : shifts) {

            long long completed = progress;
            if (idx > 0)
                completed += prefix[idx - 1];

            completed += shift;

            if (completed >= total) {
                ans.push_back(0);
                idx = 0;
                progress = 0;
                continue;
            }

            idx = upper_bound(prefix.begin(), prefix.end(), completed) - prefix.begin();

            long long prev = (idx == 0 ? 0 : prefix[idx - 1]);
            progress = completed - prev;

            ans.push_back(n - idx);
        }

        return ans;
    }
};