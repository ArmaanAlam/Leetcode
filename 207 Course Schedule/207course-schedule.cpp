class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> adj[numCourses];
        vector<int> ans;
        queue<int> q;
        vector<int> indegree(numCourses, 0);
        for(auto edge : prerequisites){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }

        for(int i = 0; i < numCourses; i++){
            for(auto node : adj[i]){
                indegree[node]++;
            }
        }

        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(int adjnode : adj[node]){
                indegree[adjnode]--;
                if(indegree[adjnode] == 0) q.push(adjnode);
            }
        }

        if(ans.size() == numCourses) return true;

        return false;
    }
};