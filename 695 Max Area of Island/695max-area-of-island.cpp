class Solution {

    int BFS(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited, int ans){

        int n = grid.size();
        int m = grid[0].size();

        visited[i][j] = true;
        queue<pair<int, int>> q;
        q.push({i, j});

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int row = r + dr[i];
                int col = c + dc[i];

                if(row < n && col < m && row >= 0 && col >= 0 && grid[row][col] && !visited[row][col]){
                    q.push({row, col});
                    visited[row][col] = true;
                    ans++;
                }
            }
        }

        return ans;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>>visited(n, vector<bool>(m, false));

        int max_area = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] && !visited[i][j]){
                    int ans = BFS(i, j, grid, visited, 1);
                    max_area = max(max_area, ans);
                }
                
            }
        }

        return max_area;
    }
};