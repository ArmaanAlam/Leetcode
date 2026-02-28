class Solution {

    void DFS(int row, int col, vector<vector<char>>& board, vector<vector<int>>& visited){
        visited[row][col] = 1;

        int n = board.size();
        int m = board[0].size();

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && !visited[nrow][ncol] && board[nrow][ncol] == 'O'){
                DFS(nrow, ncol, board, visited);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        for(int i = 0; i < m; i++){
            if(!visited[0][i] && board[0][i] == 'O'){
                DFS(0, i, board, visited);
            }
            if(!visited[n-1][i] && board[n-1][i] == 'O'){
                DFS(n-1, i, board, visited);
            }
        }
        for(int i = 0; i < n; i++){
            if(!visited[i][0] && board[i][0] == 'O'){
                DFS(i, 0, board, visited);
            }
            if(!visited[i][m-1] && board[i][m-1] == 'O'){
                DFS(i, m-1, board, visited);
            }
        }


        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};