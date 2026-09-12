class Solution {
    
    void function(int n, vector<string>& ans, string temp, char lastchar) {
        
        if (temp.size() == n) {
            ans.push_back(temp);
            return;
        }

        if (lastchar != '0') {
            
            temp.push_back('0');
            function(n, ans, temp, '0');
            temp.pop_back();

            temp.push_back('1');
            function(n, ans, temp, '1');
            temp.pop_back();
        }
        else {
            temp.push_back('1');
            function(n, ans, temp, '1');
            temp.pop_back();
        }
    }

public:

    vector<string> validStrings(int n) {
        vector<string> ans;
        string temp;

        function(n, ans, temp, '1');

        return ans;
    }
};