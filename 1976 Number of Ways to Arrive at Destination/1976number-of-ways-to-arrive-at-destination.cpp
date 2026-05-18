class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        const int mod = 1e9 + 7;

        // Adjacency list
        vector<vector<pair<int,int>>> adj(n);

        for(auto &it : roads){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        // Distance array
        vector<long long> distance(n, LLONG_MAX);

        // Ways array
        vector<int> ways(n, 0);

        // Min heap -> {distance, node}
        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        distance[0] = 0;
        ways[0] = 1;

        pq.push({0, 0});

        while(!pq.empty()){

            auto it = pq.top();
            pq.pop();

            long long dis = it.first;
            int node = it.second;


            for(auto it : adj[node]){

                int adjnode = it.first;
                int wt = it.second;

                // Found shorter path
                if(dis + wt < distance[adjnode]){

                    distance[adjnode] = dis + wt;

                    pq.push({distance[adjnode], adjnode});

                    ways[adjnode] = ways[node];
                }

                // Found another shortest path
                else if(dis + wt == distance[adjnode]){

                    ways[adjnode] =
                        (ways[adjnode] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1] % mod;
    }
};