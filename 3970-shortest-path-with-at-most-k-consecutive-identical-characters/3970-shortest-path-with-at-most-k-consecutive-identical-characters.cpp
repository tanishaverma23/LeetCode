class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto& edge: edges){
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];

            adj[u].push_back({v,w});
        }

        priority_queue<tuple<long long, int, int >,
        vector<tuple<long long , int, int >>,
        greater<tuple<long long , int , int >>>pq;

        vector<vector<long long>>dist(n,vector<long long>(k+1,LLONG_MAX));

        int start_count=1;

        pq.push({0,0,start_count});

        dist[0][start_count]=0;

        while(!pq.empty()){
            auto[w,u,count]=pq.top();
            pq.pop();

            if(u==n-1){
                return w;
            }

            if(w>dist[u][count]){
                continue;
            }

            for(auto& edge :adj[u]){
                int v=edge.first;
                int weight=edge.second;
                
                int next_count=1;
                if(labels[u]==labels[v]){
                    next_count=count+1;
                }
                if (next_count > k) {
                    continue;
                }
                
                long long next_weight = w + weight;
                if (next_weight < dist[v][next_count]) {
                    dist[v][next_count] = next_weight;
                    pq.push({next_weight, v, next_count});
                }
            }
        }
        return -1;
    }
};