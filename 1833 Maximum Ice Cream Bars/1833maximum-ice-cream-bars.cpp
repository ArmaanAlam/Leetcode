class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        
        sort(costs.begin(), costs.end());
        int n = costs.size();
        int max_count = 0;

        for(int i = 0; i < n; i++){
            if(coins > 0 && coins >= costs[i]){
                coins -= costs[i];
                max_count++;
            }
        }
        return max_count;
    }
};