#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int profit=0, sellout = prices[prices.size()-1];
        for (int i=prices.size()-2; i>=0; i--){
            if (prices[i]>sellout) sellout = prices[i];
            profit = max(profit, sellout-prices[i]);
        }
        return profit;
    }
};