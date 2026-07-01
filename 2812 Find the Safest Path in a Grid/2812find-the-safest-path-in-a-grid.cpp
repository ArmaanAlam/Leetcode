class Solution {

    

public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        
        int n = grid.size();

        vector<vector<int>>dist(n, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        int ans = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]){
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

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

                if(row < n && row >= 0 && col < n && col >= 0 && dist[row][col] == INT_MAX){
                    dist[row][col] = dist[r][c] + 1;
                    q.push({row, col});
                }
            }
        }

        priority_queue<pair<int, pair<int,int>>> pq;
        vector<vector<int>> max_safe(n, vector<int>(n, -1));

        max_safe[0][0] = dist[0][0];
        pq.push({dist[0][0], {0, 0}});

        while(!pq.empty()){
            auto it = pq.top();
            int safe = it.first;
            int row = it.second.first;
            int col = it.second.second;
            pq.pop();

            if(row == n-1 && col == n-1){
                return safe;
            }

            for(int i = 0; i < 4; i++){
                int nrow = row + dr[i];
                int ncol = col + dc[i];

                if(nrow < n && nrow >= 0 && ncol < n && ncol >= 0){
                    int newsafe = min(safe, dist[nrow][ncol]);
                    if(newsafe > max_safe[nrow][ncol]){
                        max_safe[nrow][ncol] = newsafe;
                        pq.push({newsafe, {nrow, ncol}});
                    }
                }
            }
        }

        return 0;

    }
};