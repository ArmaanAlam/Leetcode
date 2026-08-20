class Solution {

    bool DFS(int node, int parent, vector<int> adj[], vector<int>& visit) {

        visit[node] = 1;

        for(auto adjnode : adj[node]) {

            if(!visit[adjnode]) {

                if(DFS(adjnode, node, adj, visit)){
                    return true;
                }
            }
            else{
                if(adjnode != parent) {
                    return true;
                }
            }
        }

        return false;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        vector<int> adj[n + 1];

        for(auto edge : edges) {

            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

            vector<int> visit(n + 1, 0);

           
            if(DFS(u, -1, adj, visit)) {
                return {u, v};
            }
        }

        return {};
    }
};