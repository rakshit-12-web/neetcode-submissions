class Solution {
public:
    int solve(int i, int buy, vector<int>& price,vector<vector<int>>&dp) {
        if (i >= price.size()) {
            return 0;
        }
        if(dp[i][buy]!=-1){
            return dp[i][buy];
        }

        int profit = 0;

        if (buy) {
        
            profit = max(-price[i] + solve(i + 1, 0, price,dp),
                         solve(i + 1, 1, price,dp));
        } else {
        
            profit = max(price[i] + solve(i + 2, 1, price,dp),
                         solve(i + 1, 0, price,dp));
        }

        return dp[i][buy]=profit;
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,-1));
        return solve(0, 1, prices,dp);
    }
};