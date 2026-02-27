class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> distance(n, vector<int>(m, 0));
        vector<vector<int>> visited(n, vector<int>(m, 0));

        queue<pair<pair<int, int>, int>> q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                }
            }
        }

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int step = q.front().second;
            q.pop();

            distance[row][col] = step;

            int delrow[] = {-1, 0, 1, 0};
            int delcol[] = {0, 1, 0, -1};

            for(int i = 0; i < 4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && visited[nrow][ncol] == 0){
                    visited[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, step + 1});
                }
            }
        }

        return distance;
    }
};