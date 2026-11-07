class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        using FreeServer = pair<int, int>;
        priority_queue<FreeServer, vector<FreeServer>, greater<FreeServer>> free_servers;

        for (int i = 0; i < n; ++i) {
            free_servers.push({servers[i], i});
        }

        using BusyServer = pair<long long, pair<int, int>>;
        priority_queue<BusyServer, vector<BusyServer>, greater<BusyServer>> busy_servers;

        vector<int> ans(m);
        long long current_time = 0;

        for (int i = 0; i < m; ++i) {
            current_time = max(current_time, (long long)i);

            while (!busy_servers.empty() && busy_servers.top().first <= current_time) {
                auto [time, server] = busy_servers.top();
                busy_servers.pop();
                free_servers.push(server);
            }

            if (free_servers.empty()) {
                current_time = busy_servers.top().first;
                while (!busy_servers.empty() && busy_servers.top().first <= current_time) {
                    auto [time, server] = busy_servers.top();
                    busy_servers.pop();
                    free_servers.push(server);
                }
            }

            auto [weight, index] = free_servers.top();
            free_servers.pop();

            ans[i] = index;
            busy_servers.push({current_time + tasks[i], {weight, index}});
        }

        return ans;
    }
};