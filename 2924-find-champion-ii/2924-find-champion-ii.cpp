class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        

        vector<int> ans;
        vector<int> indegree(n, 0);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            indegree[v]++;
        }

        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                ans.push_back(i);
            }
        }

        return ans.size() == 1 ? ans[0] : -1; 
    }
};