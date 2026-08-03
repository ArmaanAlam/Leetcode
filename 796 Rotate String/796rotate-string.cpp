class Solution {
public:
    bool rotateString(string s, string goal) {

        if(s.length() != goal.length()) return false;
        
        string str = s+s;
        
        for(int i = 0; i < str.length(); i++){
            int j = 0;
            if(str[i] == goal[j]){
                while(str[j+i] == goal[j]){
                    j++;
                }
                if(j == goal.length()) return true;
            }
        }
        return false;
    }
};