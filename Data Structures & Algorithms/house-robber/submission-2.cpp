class Solution {
public:
int solve(int i,vector<int>&nums,vector<int>&dp){
    if(dp[i]!=-1){
        return dp[i];
    }
    if(i>=nums.size()){
        return dp[i]= 0;
    }
    int take=nums[i]+solve(i+2,nums,dp);
    int nottake=solve(i+1,nums,dp);
    return dp[i]=max(take,nottake);

}
    int rob(vector<int>& nums) {
        vector<int>dp(300,-1);
        return solve(0,nums,dp);
    }
};
