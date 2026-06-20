class Solution {
public:
    vector<string> createGrid(int m, int n) {

        vector<vector<char>> grid(m, vector<char>(n, '#'));

        bool direction_right = true;

        int row = 0;
        int col = 0;
        grid[row][col] = '.';

        while(row != m-1 || col != n-1){
            
            grid[row][col] = '.';
            if(direction_right && col < n-1){
                col++;
            }
            else if(!direction_right && row < m-1){
                row++;
            }
            else if(col < n-1){
                col++;
            }
            else{
                row++;
            }
            
            grid[row][col] = '.';
            direction_right = ! direction_right;
        }

        vector<string> ans;
        for(int i = 0; i < m; i++){
            string temp;
            for(int j = 0; j < n; j++){
                temp.push_back(grid[i][j]);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};