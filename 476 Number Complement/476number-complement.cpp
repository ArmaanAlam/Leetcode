class Solution {
public:
    int findComplement(int num) {
        
        int n = num;
        int bits = 0;

        while(n){
            bits++;
            n >>= 1;
        }

        unsigned int mask = (1u << bits) - 1;

        int res = mask ^ num;

        return res;
    }
};