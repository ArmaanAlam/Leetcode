class Solution {
public:

    int palindrome(string &s, int i, int j){
        
        int count = 0;

        while( i>=0 && j < s.length() && s[i] == s[j]){
            count++;
            i--;
            j++;
        }
        return count;
    }
    int countSubstrings(string s) {

       int count = 0;
       int n = s.length();

       for(int i=0; i<n; i++){

        int Oddcount = palindrome(s, i, i);
        count = count + Oddcount;

        int Evencount = palindrome(s, i, i+1);
        count = count + Evencount;
       } 
       return count;
    }
};