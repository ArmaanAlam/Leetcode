class Solution {

    long long pow(long long a, long long b){

        int mod = 1e9 + 7;

        long long ans = 1;

        while(b > 0){
            if(b & 1){
                ans = (ans * a) % mod;
            }
            a = (a * a) % mod;
            b >>= 1;
        }

        return ans;
    }

public:
    int countGoodNumbers(long long n) {
        
        int mod = 1e9 + 7;

        return (pow(5, (n + 1)/2) * pow(4, n/2)) % mod;
    }
};