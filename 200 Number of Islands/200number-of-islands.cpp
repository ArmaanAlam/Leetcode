class Solution {

    void BFS(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &visited){

        visited[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});

        int n = grid.size();
        int m = grid[0].size();

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int delrow = -1; delrow <= 1; delrow++){
                for(int delcol = -1; delcol <= 1; delcol++){
                    int nrow = row + delrow;
                    int ncol = col + delcol;

                    if(abs(delrow) + abs(delcol) != 1) continue;

                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                       !visited[nrow][ncol] && grid[nrow][ncol] == '1'){
                        visited[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        int count = 0;

        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(!visited[row][col] && grid[row][col] == '1'){
                    count++;
                    BFS(row, col, grid, visited);
                }
            }
        }

        return count;
    }
};