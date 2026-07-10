class Solution {

    int DFS(vector<vector<int>>& grid, int r, int c, vector<vector<int>> &dp){

        int n = grid.size();
        int m = grid[0].size();

        if(r == n-1 && c == m - 1){
            return grid[r][c];
        }

        if (dp[r][c] != -1){
            return dp[r][c];
        }

        int down = INT_MAX;
        int right = INT_MAX;
        
        if(r + 1 < n){
           right = DFS(grid, r + 1, c, dp);
        }
        
        if(c + 1 < m){
           down = DFS(grid, r, c + 1, dp);
        }

        return dp[r][c] = grid[r][c] + min(right, down);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        if(n == 1 && m == 1) return grid[0][0];

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return DFS(grid, 0, 0, dp);
    }
};