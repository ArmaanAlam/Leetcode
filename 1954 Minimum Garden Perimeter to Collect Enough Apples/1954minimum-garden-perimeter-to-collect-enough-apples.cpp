class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long layer = 0;
        long long sum = 0;

        while(sum < neededApples){
            layer++;
            sum += 12*layer*layer;
        }
        return 8*layer;
    }
};