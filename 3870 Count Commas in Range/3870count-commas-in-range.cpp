class Solution {
public:
    int countCommas(int n) {
        int cnt = 0;
        int i = 1;
        while(i <= n){
            if(i >= 1000){
                cnt++;
            }
            i++;
        }

        return cnt;
    }
};