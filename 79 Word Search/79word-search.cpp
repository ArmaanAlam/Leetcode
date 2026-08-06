class Solution {

    bool DFS(vector<vector<char>>& board, string word, int i, int j,
             int index) {

        int n = board.size();
        int m = board[0].size();

        if (index == word.size())
            return true;

        if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] != word[index]) {
            return false;
        }

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        char temp = board[i][j];
        board[i][j] = '#';

        for (int k = 0; k < 4; k++) {
            int row = i + dr[k];
            int col = j + dc[k];

            if (DFS(board, word, row, col, index + 1)) {
                board[i][j] = temp;
                return true;
            }
        }

        board[i][j] = temp;

        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (DFS(board, word, i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};