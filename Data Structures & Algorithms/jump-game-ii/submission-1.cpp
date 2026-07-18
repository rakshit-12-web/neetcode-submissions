class Solution {
public:
int maxi=INT_MAX;
bool solve(int i,int n,vector<int>&nums,vector<vector<int>>&dp){
      if(i==nums.size()-1){
        maxi=min(maxi,n);
        return dp[i][n]=INT_MAX;
    }
    if(i>=nums.size()){
        return INT_MAX;
    }
    if(dp[i][n]!=-1){
        return dp[i][n];
    }
  
    for(int j=i;j<nums[i]+i;j++){
        solve(j+1,n+1,nums,dp);
    }
return dp[i][n]=INT_MAX;
}
    int jump(vector<int>& nums) {
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        solve(0,0,nums,dp);
        return maxi;
        
    }
};
