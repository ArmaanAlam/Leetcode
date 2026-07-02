class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        dist[0][0] = grid[0][0];
        q.push({0, 0});

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while(!q.empty()){
            auto it = q.front();
            int r = it.first;
            int c = it.second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int row = r + dr[i];
                int col = c + dc[i];

                if(row < n && row >= 0 && col < m && col >= 0 && dist[r][c] + grid[row][col] < dist[row][col]){
                    dist[row][col] = dist[r][c] + grid[row][col];
                    q.push({row, col});
                }
            }

        }

        return dist[n - 1][m - 1] < health;
    }
};