class Solution {
    
    void reversstring(vector<char> &str, int s, int e){

        if(s > e) return;

        swap(str[s], str[e]);

        reversstring(str, s+1, e-1);
    }

public:
    void reverseString(vector<char>& s) {

        reversstring(s, 0, s.size()-1);
    }
};