class Solution {

    bool isSafe(int garden, vector<int> adj[],
                vector<int>& color, int flow) {

        for (auto adjgarden : adj[garden]) {

            if (color[adjgarden] == flow) {
                return false;
            }
        }

        return true;
    }

public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {

        vector<int> adj[n + 1];

        for (auto it : paths) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> color(n + 1, 0);

        for (int garden = 1; garden <= n; garden++) {

            for (int flow = 1; flow <= 4; flow++) {

                if (isSafe(garden, adj, color, flow)) {
                    color[garden] = flow;
                    break;
                }
            }
        }

        color.erase(color.begin());

        return color;
    }
};