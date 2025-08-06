class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int length = 0;

        int r = s.length()-1;

        while(r >= 0 && s[r] == ' '){
            r--;
        }

        while(r >= 0 && s[r] != ' '){
            length++;
            r--;
        }

        return length;
    }
};