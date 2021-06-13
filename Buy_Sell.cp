// for all values of K
// for fee in transaction do sell[j] = max(sell[j],buy[j]+prices[i]-fee)
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(k==0)return 0;
        if(prices.size()==1)return 0;
        
        vector<int> buy(k, INT_MIN);
        vector<int> sell(k,0);
        int answer = 0;
        
        for(int i=0;i<prices.size();i++){
            for(int j=0;j<buy.size();j++){
                if(j==0)buy[j] = max(buy[j],-prices[i]);
                else buy[j] = max(buy[j],sell[j-1]-prices[i]);
                sell[j] = max(sell[j],buy[j]+prices[i]);
            }
        }
        
        return sell[k-1];
    }
};

