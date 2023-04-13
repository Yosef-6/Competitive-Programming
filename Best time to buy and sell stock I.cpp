class Solution {
public:
    int maxProfit(vector<int>& prices) {
     
        int profit = 0;
        size_t buyIndex=0; 
        for(size_t sellIndex = 1; sellIndex<prices.size(); sellIndex++){
          if(prices[sellIndex] - prices[buyIndex]  < 0 )
              buyIndex = sellIndex;
         else
             profit = std::max(prices[sellIndex] - prices[buyIndex],profit);
            
            
        }
        
        
        return profit;
    }
};
