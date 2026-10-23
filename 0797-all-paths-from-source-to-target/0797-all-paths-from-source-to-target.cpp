class Solution {

    void DFS(vector<vector<int>>& graph, vector<vector<int>>& paths, vector<int> curr_path, int node){

        curr_path.push_back(node);
        
        int n = graph.size();
        if(node >= n-1){
            paths.push_back(curr_path);
            return;
        }

        for(int adjnode : graph[node]){
            DFS(graph, paths, curr_path, adjnode);
        }
        curr_path.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<vector<int>> paths;
        vector<int> curr_path;
        DFS(graph, paths, curr_path, 0);
        return paths;
    }
};