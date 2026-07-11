class Solution {
public:
    string removeOuterParentheses(string s) {
        
        int n = s.size();
        int cnt = 0;
        int start = 0;
        vector<string> valid;

        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                cnt++;
            }
            else{
                cnt--;
            }

            if(cnt == 0){
                valid.push_back(s.substr(start + 1, i - start - 1));
                start = i + 1;
            }
        }

        string ans;
        for(string str : valid){
            ans += str;
        }

        return ans;
    }
};