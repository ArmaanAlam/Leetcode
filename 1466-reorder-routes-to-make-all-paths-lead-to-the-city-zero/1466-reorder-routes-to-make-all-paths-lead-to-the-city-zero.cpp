class Solution {

    void DFS(vector<pair<int, int>> adj[], vector<bool>& visit, int& count,
             int node) {

        visit[node] = true;

        for (auto [adjnode, direction] : adj[node]) {
            if (!visit[adjnode]) {
                count += direction;
                DFS(adj, visit, count, adjnode);
            }
        }
    }

public:
    int minReorder(int n, vector<vector<int>>& connections) {

        vector<pair<int, int>> adj[n];
        for (auto& edge : connections) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back({v, 1});
            adj[v].push_back({u, 0});
        }

        vector<bool> visit(n, false);

        int count = 0;

        DFS(adj, visit, count, 0);

        return count;
    }
};