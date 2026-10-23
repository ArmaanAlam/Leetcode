class Solution {


    bool isValid(vector<vector<int>>& grid, vector<vector<bool>>& visit, int nrow, int ncol){

        int n = grid.size();
        int m = grid[0].size();

        return nrow < n && ncol < m && nrow >= 0 && ncol >= 0 && grid[nrow][ncol] > 0 && !visit[nrow][ncol];

    }

    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visit, int r, int c){

        queue<pair<int, int>>q;
        q.push({r, c});
        visit[r][c] = true;
        int ans = 0;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            ans += grid[row][col];
            q.pop();

            for(int i = 0; i < 4; i++){
                int nrow = row + dr[i];
                int ncol = col + dc[i];

                if(isValid(grid, visit, nrow, ncol)){
                    q.push({nrow, ncol});
                    visit[nrow][ncol] = true;
                }
            }
        }

        return ans;
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visit(n, vector<bool>(m, false));

        int ans = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visit[i][j] && grid[i][j] > 0){
                    int temp = dfs(grid, visit, i, j);
                    ans = max(ans, temp);
                }
            }
        }

        return ans;

    }
};