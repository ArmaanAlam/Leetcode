class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<int> adj[n];
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        queue<int> q;
        vector<int> visited(n, 0);

        q.push(source);
        visited[source] = 1;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            if(node == destination) return true;

            for(auto adjnode : adj[node]){
                if(!visited[adjnode]){
                    q.push({adjnode});
                    visited[adjnode] = 1;
                }
            }
        }

        return false;
    }
};