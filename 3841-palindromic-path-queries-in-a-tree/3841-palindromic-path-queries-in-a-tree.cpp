#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
private:
    int n;
    vector<vector<int>> adj;
    vector<int> parent, depth, heavy, head, pos;
    vector<int> sub_sz;
    vector<int> tree_val;
    vector<int> seg_tree;
    int cur_pos;

    void dfs1(int u, int p, int d) {
        depth[u] = d;
        parent[u] = p;
        sub_sz[u] = 1;
        int max_sz = 0;
        for (int v : adj[u]) {
            if (v != p) {
                dfs1(v, u, d + 1);
                sub_sz[u] += sub_sz[v];
                if (sub_sz[v] > max_sz) {
                    max_sz = sub_sz[v];
                    heavy[u] = v;
                }
            }
        }
    }

    void dfs2(int u, int h) {
        head[u] = h;
        pos[u] = cur_pos++;
        if (heavy[u] != -1) {
            dfs2(heavy[u], h);
        }
        for (int v : adj[u]) {
            if (v != parent[u] && v != heavy[u]) {
                dfs2(v, v);
            }
        }
    }

    void update_seg(int node, int start, int end, int idx, int val) {
        if (start == end) {
            seg_tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (start <= idx && idx <= mid)
            update_seg(2 * node, start, mid, idx, val);
        else
            update_seg(2 * node + 1, mid + 1, end, idx, val);
        seg_tree[node] = seg_tree[2 * node] ^ seg_tree[2 * node + 1];
    }

    int query_seg(int node, int start, int end, int l, int r) {
        if (r < start || end < l)
            return 0;
        if (l <= start && end <= r)
            return seg_tree[node];
        int mid = (start + end) / 2;
        return query_seg(2 * node, start, mid, l, r) ^ query_seg(2 * node + 1, mid + 1, end, l, r);
    }

    int query_path(int u, int v) {
        int res = 0;
        while (head[u] != head[v]) {
            if (depth[head[u]] > depth[head[v]]) {
                res ^= query_seg(1, 0, n - 1, pos[head[u]], pos[u]);
                u = parent[head[u]];
            } else {
                res ^= query_seg(1, 0, n - 1, pos[head[v]], pos[v]);
                v = parent[head[v]];
            }
        }
        if (depth[u] > depth[v]) {
            res ^= query_seg(1, 0, n - 1, pos[v], pos[u]);
        } else {
            res ^= query_seg(1, 0, n - 1, pos[u], pos[v]);
        }
        return res;
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        this->n = n;
        adj.assign(n, vector<int>());
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        parent.assign(n, -1);
        depth.assign(n, 0);
        heavy.assign(n, -1);
        head.assign(n, 0);
        pos.assign(n, 0);
        sub_sz.assign(n, 0);
        tree_val.assign(n, 0);
        seg_tree.assign(4 * n, 0);
        cur_pos = 0;

        dfs1(0, -1, 0);
        dfs2(0, 0);

        for (int i = 0; i < n; ++i) {
            int mask = 1 << (s[i] - 'a');
            tree_val[pos[i]] = mask;
            update_seg(1, 0, n - 1, pos[i], mask);
        }

        vector<bool> answer;
        for (const string& q : queries) {
            if (q[0] == 'u') {
                int space1 = q.find(' ', 7);
                int u = stoi(q.substr(7, space1 - 7));
                char c = q.back();

                int new_mask = 1 << (c - 'a');
                update_seg(1, 0, n - 1, pos[u], new_mask);
            } else {
                int space1 = q.find(' ', 6);
                int space2 = q.find(' ', space1 + 1);
                int u = stoi(q.substr(6, space1 - 6));
                int v = stoi(q.substr(space1 + 1));

                int path_mask = query_path(u, v);
                if ((path_mask & (path_mask - 1)) == 0) {
                    answer.push_back(true);
                } else {
                    answer.push_back(false);
                }
            }
        }

        return answer;
    }
};