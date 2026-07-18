class Solution {
public:
bool solve(int i,vector<int>&nums){
      if(i==nums.size()-1){
        return true;
    }
    if(i>=nums.size()){
        return false;
    }
  
    for(int j=i;j<nums[i]+i;j++){
        if(solve(j+1,nums)){
            return true;
        }
    }
    return false;
}
    bool canJump(vector<int>& nums) {
        return solve(0,nums);
        
    }
};
