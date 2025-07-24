class Solution {
public:
    string convert(string s, int numRows) {
        
        vector<string> zigzag(numRows);
        int row = 0;
        int i = 0;
        bool direction = 1;

        if(numRows == 1) return s;

        while(true){

            if(direction){
                while(row < numRows  &&  i < s.length()){
                    zigzag[row].push_back(s[i]);
                    i++;
                    row++;
                }
                row = numRows - 2;
            }
            else{
                while(row >= 0  && i < s.length()){
                    zigzag[row].push_back(s[i]);
                    row--;
                    i++;
                }
                row = 1;
            }

            direction = !direction;

            if(i >= s.length()){
                break;
            }
        } 

        string ans = "";

        for(int i = 0; i < zigzag.size(); i++){
            ans += zigzag[i];
        }

        return ans;
    }
};