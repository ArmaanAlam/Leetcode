class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        
        vector<vector<int>> adjRev(V);
        vector<int> indegree(V, 0);
        vector<int> ans;
        queue<int> q;

        for(int i = 0; i < V; i++){
            for(auto it : graph[i]){
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }

    
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

   
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto adjnode : adjRev[node]){
                indegree[adjnode]--;
                if(indegree[adjnode] == 0){
                    q.push(adjnode);
                }
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};