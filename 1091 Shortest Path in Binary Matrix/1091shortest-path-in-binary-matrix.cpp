class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        if(grid[0][0] == 1) return -1;
        if(n == 1 && m == 1) return 1;

        vector<vector<int>>distance(n, vector<int>(m, INT_MAX));
        queue<pair<int, pair<int, int>>> q;

        distance[0][0] = 1;
        q.push({1, {0, 0}});

        int rw[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int cw[] = {0, 1, 1, 1, 0, -1, -1, -1};

        while(!q.empty()){
            auto it = q.front();
            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;
            q.pop();

            for(int i = 0; i < 8; i++){
                int nrow = row + rw[i];
                int ncol = col + cw[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                   grid[nrow][ncol] == 0 && dis + 1 < distance[nrow][ncol]){

                    if(nrow == n-1 && ncol == m-1) return dis + 1;

                    distance[nrow][ncol] = dis + 1;
                    q.push({distance[nrow][ncol], {nrow, ncol}});
                }
            }
        }

        return -1;
    }
};