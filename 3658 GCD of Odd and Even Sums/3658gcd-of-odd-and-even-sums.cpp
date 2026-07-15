class Solution {

    int fun(int a, int b){

        if(b == 0) return a;
        return fun(b, a % b);
    }
public:
    int gcdOfOddEvenSums(int n) {
        
        int a = 0;
        int b = 0;
        int i = 1;

        while(n--){
            a = a + (1 + (2*i));
            b = b + (2*i);
        }

        return fun(a,b);
    }
};