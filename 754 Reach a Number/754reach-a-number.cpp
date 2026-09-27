class Solution {
public:
    int reachNumber(int target) {
        
        target = abs(target);

        int k = 0;
        int sum = 0;

        while(sum < target){
            k++;
            sum += k;
        }

        int delta = sum - target;

        if(delta % 2 == 0){
            return k;
        }

        if(k % 2 == 1){
            return k + 2;
        }

        return k + 1;
    }
};