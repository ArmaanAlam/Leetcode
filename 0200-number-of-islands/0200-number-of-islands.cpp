class Solution {

    bool isValid(int n, int m, int row, int col, vector<vector<char>>& grid, vector<vector<int>>& visit){
        return row < n && col < m && row >= 0 && col >= 0 && !visit[row][col] && grid[row][col] == '1';
    }

    void BFS(vector<vector<char>>& grid, vector<vector<int>>& visit, int r, int c){

        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({r, c});
        visit[r][c] = 1;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
            int row = r + dr[i];
            int col = c + dc[i];

            if(isValid(n, m, row, col, grid, visit)){
                q.push({row, col});
                visit[row][col] = 1;
            }
        }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {

        if (grid.empty() || grid[0].empty()) return 0;
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visit(n, vector<int>(m, 0));
        int count = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1' && !visit[i][j]){
                    BFS(grid, visit, i, j);
                    count++;
                }
            }
        }

        return count;
    }
};