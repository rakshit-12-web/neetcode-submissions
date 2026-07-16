class Solution {
public:
int solve(int i,vector<int>&nums,int amount){

    if(amount==0){
        return 0;
    }
    if(i>=nums.size()||amount<0){
        return 1e9;
    }
    int nottake=solve(i+1,nums,amount);
    int take=1+solve(i,nums,amount-nums[i]);
    
    return min(take,nottake);

}
    int coinChange(vector<int>& coins, int amount) {
      int ans = solve(0, coins, amount);

if(ans >= 1e9)
    return -1;

return ans;
        
    }
};
