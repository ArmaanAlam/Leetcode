class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        
        minvalue = float('inf')
        profit = 0


        for price in prices:

            if price < minvalue:
                minvalue = price
            
            profit = max(profit, price - minvalue)
        
        return profit