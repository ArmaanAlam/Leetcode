class Solution {
    void parentheses(vector<string>& ans, int rem_open, int rem_closed, string output) {
        if(rem_open == 0 && rem_closed == 0){   
            ans.push_back(output);
            return;
        }

        if(rem_open > 0){
            output.push_back('(');              
            parentheses(ans, rem_open - 1, rem_closed, output);    
            output.pop_back(); 
        }

        if(rem_open < rem_closed){
            output.push_back(')');            
            parentheses(ans, rem_open, rem_closed - 1, output);
            output.pop_back(); 
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string output = "";                      
        parentheses(ans, n, n, output);
        return ans;
    }
};
