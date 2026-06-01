class Solution {
public:
    int minimumCost(vector<int>& cost) {

        sort(cost.begin(), cost.end(), greater<int>());

        int min_cost = 0;
        
        for(int i = 0; i < cost.size(); i += 3){
            min_cost += cost[i];
            if(i+1 < cost.size()) min_cost += cost[i+1];
        }

        return min_cost;
    }
};