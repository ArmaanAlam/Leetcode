class Solution {

    double pow(double a, long long b){

        if(b == 0) return 1;

        double ans = pow(a, b / 2);

        if(b % 2 == 0){
            return ans*ans;
        }

        return a*ans*ans;
    }
public:
    double myPow(double x, int n) {

        long long N = n;

        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        return pow(x, N);
    }
};