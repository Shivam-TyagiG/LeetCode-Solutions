class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
         sort(prices.begin(), prices.end());
        int start = money;
        money -= (prices[0] + prices[1]);
        if(money < 0) return start;
        else return money ;
    }
};