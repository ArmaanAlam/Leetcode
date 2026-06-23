class Solution {
public:
    bool checkValidString(string s) {
        
        int n = s.size();
        int min_range = 0;
        int max_range = 0;

        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                min_range = min_range + 1;
                max_range = max_range + 1;
            }
            else if(s[i] == ')'){
                min_range = min_range - 1;
                max_range = max_range - 1;
            }
            else{
                min_range = min_range - 1;
                max_range = max_range + 1;
            }

            if(min_range < 0) min_range = 0;

            if(max_range < 0) return false;
        }

        return (min_range == 0);

    }
};