class Solution {
public:
bool solve(int i,vector<int>&nums,int total,vector<vector<int>>&dp){
    if(total==0){
        return true;
    }
 
    if(i>=nums.size()||total<0){
        return false;
    }
       if(dp[i][total]!=-1){
        return dp[i][total];
    }

    bool take=solve(i+1,nums,total-nums[i],dp);
    bool nottake=solve(i+1,nums,total,dp);
    return dp[i][total]=nottake||take;
    
}
    bool canPartition(vector<int>& nums) {
        int total=0;
        for(auto & x:nums){
            total+=x;
        }
        if(total%2!=0){
            return false;
        }
        total=total/2;
      vector<vector<int>> dp(nums.size(),
                       vector<int>(total+ 1, -1));
       return solve(0,nums,total,dp);

        
    }
};
