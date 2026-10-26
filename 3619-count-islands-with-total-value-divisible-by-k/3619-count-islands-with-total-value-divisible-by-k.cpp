class Solution {

    bool BFS(vector<vector<int>> &grid, int k, vector<vector<bool>>& visit, int i, int j){

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        visit[i][j] = true;
        q.push({i, j});

        long long count = 0;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            count += grid[r][c];
            q.pop();

            for(int k = 0; k < 4; k++){
                int row = r + dr[k];
                int col = c + dc[k];

                if(row < 0 || col < 0 || row >= n || col >= m || visit[row][col] || grid[row][col] == 0){
                    continue;
                }

                q.push({row, col});
                visit[row][col] = true;
            }
        }

        return count % k ==  0;
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visit(n, vector<bool>(m, false));
        int cnt = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visit[i][j] && grid[i][j] != 0){
                    if(BFS(grid, k, visit, i, j)){
                        cnt++;
                    }
                }
            }
        }

        return cnt;

    }
};