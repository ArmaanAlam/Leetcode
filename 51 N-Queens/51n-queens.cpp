class Solution {


    unordered_map<int, bool> leftRow;
    unordered_map<int, bool> Upperleft;
    unordered_map<int, bool> Bottomleft;

    void storeQueen(vector<vector<char>>& chess, int n, vector<vector<string>>& ans){
        vector<string> temp;

        for(int i = 0; i < n; i++){

            string output = "";

            for(int j = 0; j < n; j++){
                output.push_back(chess[i][j]);
            }

            temp.push_back(output);
        }
        ans.push_back(temp);
    }

    bool place(vector<vector<char>>& chess, int n, int row, int col){



    if (leftRow[row] == true)
    {
        return false;
    }

    if (Upperleft[n - 1 + col - row] == true)
    {
        return false;
    }

    if (Bottomleft[row + col] == true)
    {
        return false;
    }

        return true;
    }

    void placeQueen(vector<vector<char>>& chess, int n, int col, vector<vector<string>>& ans){

        if(col >= n){
            storeQueen(chess, n, ans);
            return;
        }

        for(int row = 0; row < n; row++){

            if(place(chess, n, row, col)){

                leftRow[row] = true;
                Upperleft[n - 1 + col - row] = true;
                Bottomleft[row + col] = true;
                chess[row][col] = 'Q';
                
                placeQueen(chess, n, col + 1, ans);

                leftRow[row] = false;
                Upperleft[n - 1 + col - row] = false;
                Bottomleft[row + col] = false;
                chess[row][col] = '.';

            }
        }
        return;
    }

public:
    vector<vector<string>> solveNQueens(int n) {

        vector<vector<char>> chess(n, vector<char>(n, '.'));

        vector<vector<string>> ans;

        placeQueen(chess, n, 0, ans);

        return ans;
    }
};
