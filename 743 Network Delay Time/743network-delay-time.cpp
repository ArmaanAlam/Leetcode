class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<pair<int, int>> adj[n+1];
        for(auto it : times){
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> distance(n+1, INT_MAX);
        
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        distance[k] = 0;
        pq.push({0, k});

        while(!pq.empty()){
            auto it = pq.top();
            int dis = it.first;
            int node = it.second;
            pq.pop();

            for(auto it : adj[node]){
                int adjnode = it.first;
                int wt = it.second;

                if(dis + wt < distance[adjnode]){
                    distance[adjnode] = dis + wt;
                    pq.push({distance[adjnode], adjnode});
                }
            }
        }

        int maxtime = INT_MIN;

        for(int i = 1; i <= n; i++){
            maxtime = max(maxtime, distance[i]);
        }

        if(maxtime == INT_MAX) return -1;

        return maxtime;
    }
};