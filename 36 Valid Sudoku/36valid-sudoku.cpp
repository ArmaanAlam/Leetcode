class Solution {

    bool isValid(vector<vector<char>>& board, int row, int col) {

        char c = board[row][col];

        for (int i = 0; i < 9; i++) {
            if (i != col && board[row][i] == c)
                return false;
            if (i != row && board[i][col] == c)
                return false;
            int r = 3 * (row / 3) + i / 3;
            int c1 = 3 * (col / 3) + i % 3;

            if ((r != row || c1 != col) && board[r][c1] == c)
                return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    continue;
                } else {
                    if (isValid(board, i, j) == false) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

public:
    bool isValidSudoku(vector<vector<char>>& board) { return solve(board); }
};