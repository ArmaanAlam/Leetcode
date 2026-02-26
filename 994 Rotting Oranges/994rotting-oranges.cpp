class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        int time = 0;
        int visited[n][m];
        queue<pair<pair<int, int>, int>> q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                    visited[i][j] = 2;
                }
                else{
                    visited[i][j] = 0;
                }
            }
        }

        while(!q.empty()){
            int r = q.front().first.first; 
            int c = q.front().first.second; 
            int t = q.front().second;
            q.pop();

            time = max(time, t);

            int delrow[] = {-1, 0, 1, 0}; 
            int delcol[] = {0, 1, 0, -1};

            for(int i = 0; i < 4; i++){
                int row = r + delrow[i];
                int col = c + delcol[i];
                if(row >= 0 && col >= 0 && row < n && col < m && grid[row][col] == 1 && visited[row][col] != 2){
                    q.push({{row, col}, t+1});
                    visited[row][col] = 2;
                }
            } 
        }


        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && visited[i][j] != 2){
                    return -1;
                }
            }
        }

        return time;

    }
};