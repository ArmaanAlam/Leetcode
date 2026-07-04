class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        
        vector<vector<pair<int, int>>> adj(n + 1);

        for(auto it : roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<bool>visit(n+1, false);
        queue<int>q;
        q.push(1);
        visit[1] = true;

        int ans = INT_MAX;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto adjnode : adj[node]){
                int v = adjnode.first;
                int weight = adjnode.second;

                ans = min(ans, weight);
                if(!visit[v]){
                    visit[v] = true;
                    q.push(v);
                }
            }
        }

        return ans;

    }
};