class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int k=prices[0];
        int maxi=0;
        for(int i=1;i<prices.size();i++){
            k=min(k,prices[i-1]);
            maxi=max(prices[i]-k,maxi);
        }
        return maxi;
    }
};
