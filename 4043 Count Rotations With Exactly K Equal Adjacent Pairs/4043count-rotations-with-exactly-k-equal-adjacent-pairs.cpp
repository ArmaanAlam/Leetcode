class Solution {
public:
    int countRotations(string s, int k) {
        
        int n = s.size();
        int total = 0;

        
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                total++;
            }
        }

       
        if (s[0] == s[n - 1]) {
            total++;
        }

       
        if (total == k) {
            return n - total;
        }

      
        if (total - 1 == k) {
            return total;
        }

        return 0;
    }
};