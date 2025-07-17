class Solution {
public:

    bool isPalindromic(string &s, int i, int j){
        while(i<j){
            if(s[i] != s[j]){
                return false;
            }
            else{
                i++;
                j--;
            }
        }
        return true;
    }
    string longestPalindrome(string s) {
        string ans = "";

        for(int i=0; i<s.length(); i++){
            for(int j=i; j<s.length(); j++){
                if(isPalindromic(s, i, j)){
                    string t = s.substr(i, j-i+1);
                    ans = t.length() > ans.length() ? t : ans;
                }
            }
        }
        return ans;
    }
};