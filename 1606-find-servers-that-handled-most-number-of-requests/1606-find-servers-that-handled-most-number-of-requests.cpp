class Solution {
public:
    std::vector<int> busiestServers(int k, std::vector<int>& arrival, std::vector<int>& load) {
        int n = arrival.size();
        std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<>> busy_pq;
        std::set<int> available;
        
        for (int i = 0; i < k; ++i) {
            available.insert(i);
        }
        
        std::vector<int> request_count(k, 0);
        
        for (int i = 0; i < n; ++i) {
            long long start = arrival[i];
            long long duration = load[i];
            
         
            while (!busy_pq.empty() && busy_pq.top().first <= start) {
                available.insert(busy_pq.top().second);
                busy_pq.pop();
            }
            
    
            if (available.empty()) {
                continue;
            }
            
            
            auto it = available.lower_bound(i % k);
            if (it == available.end()) {
                it = available.begin(); 
            }
            
            int server_id = *it;
            available.erase(it);
            
            busy_pq.push({start + duration, server_id});
            request_count[server_id]++;
        }
        
        int max_requests = 0;
        for (int count : request_count) {
            max_requests = std::max(max_requests, count);
        }
        
        std::vector<int> busiest;
        for (int i = 0; i < k; ++i) {
            if (request_count[i] == max_requests) {
                busiest.push_back(i);
            }
        }
        
        return busiest;
    }
};