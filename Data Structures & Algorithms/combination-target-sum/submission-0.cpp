class Solution {
public:
void solve(vector<vector<int>>&ans,vector<int>&temp,vector<int>&nums,int target,int i){
    if(i>=nums.size()){
        return ;
    }
    if(target<0){
        return;
    }
    if(target==0)
    {
    ans.push_back(temp);
    return;
    }
    for(int j=i;j<nums.size();j++){
    temp.push_back(nums[j]);
    solve(ans,temp,nums,target-nums[j],j);
          temp.pop_back();
    }
}
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(ans,temp,nums,target,0);
        return ans;
        
    }
};
