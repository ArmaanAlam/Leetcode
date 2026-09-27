class Solution {

    bool helper(string &s, int left, int right){
        while(left < right){
            if(s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        
        int n = s.size();
        int left = 0;
        int right = n-1;

        while(left < right){
            if(s[left] != s[right]){
                return helper(s, left, right-1) || helper(s, left+1, right);
            }
            left++;
            right--;
        }

        return true;
    }
};