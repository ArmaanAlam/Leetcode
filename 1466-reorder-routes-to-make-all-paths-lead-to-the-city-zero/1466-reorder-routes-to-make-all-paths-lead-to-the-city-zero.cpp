
class Solution {
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
        queue<int> q;

        q.push(0);
        visit[0] = true;

        int count = 0;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            for (auto [adjnode, direction] : adj[node]) {

                if (!visit[adjnode]) {

                    count += direction;

                    visit[adjnode] = true;
                    q.push(adjnode);
                }
            }
        }

        return count;
    }
};
