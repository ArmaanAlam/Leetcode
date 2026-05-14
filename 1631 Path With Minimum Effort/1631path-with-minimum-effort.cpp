class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>>distance(n, vector<int>(m, INT_MAX));

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>      
        >pq;

        distance[0][0] = 0;
        pq.push({0, {0, 0}});

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while(!pq.empty()){
            auto it = pq.top();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;
            pq.pop();

            if(row == n-1 && col == m-1) return diff;

            for(int i = 0; i < 4; i++){
                int nrow = row + dr[i];
                int ncol = col + dc[i];
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m){

                    int newdiff = max(diff, abs(heights[row][col] - heights[nrow][ncol]));

                    if(newdiff < distance[nrow][ncol]){
                        distance[nrow][ncol] = newdiff;
                        pq.push({distance[nrow][ncol], {nrow, ncol}});
                    }
                }

            }
        }
        return 0;
    }
};