class Solution {
public:
int solve(int i,int target,vector<int>&nums,int n){
         if(i==nums.size()){
    if(n==target){
        return 1;
    }
    }
      if(i==nums.size()){
    if(n>target||n<0){
        return 0;
    }
    }
    if(i>=nums.size()){
    return 0;
}
    int sub=solve(i+1,target,nums,n+nums[i]);
    int add=solve(i+1,target,nums,n-nums[i]);
   
    return sub+add;

}
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        return solve(0,target,nums,sum);
        
    }
};
