class Solution {

    int  DFS(vector<vector<int>>& obstacleGrid, int i, int j,
    vector<vector<int>>& dp){
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        if((i >= n || j >= m) || obstacleGrid[i][j] == 1){
            return 0;
        }

        if(i == n-1 && j == m-1){
            return 1;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int right = DFS(obstacleGrid, i, j+1, dp);
        int down = DFS(obstacleGrid, i+1, j, dp);

        return dp[i][j] = right + down;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return DFS(obstacleGrid, 0, 0, dp);
    }
};