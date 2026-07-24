class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int min_price = INT_MAX;
        int profit = INT_MIN;

        for(int i = 0; i < n; i++){
            if(prices[i] < min_price){
                min_price = prices[i];
            }

            int currprofit = prices[i] - min_price;

            if(currprofit > profit){
                profit = currprofit;
            }
        }

        return profit;
    }
};