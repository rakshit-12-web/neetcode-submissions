class Solution {
public:
void solve(int i,vector<int>&nums,vector<vector<int>>&ans,vector<int>&temp){
    if(i>=nums.size()){
        ans.push_back(nums);
        return;
    }
    for(int j=i;j<nums.size();j++){  
  swap(nums[i],nums[j]);
  solve(i+1,nums,ans,temp);
  swap(nums[i],nums[j]);
}
}

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(0,nums,ans,temp);
return ans;
        
    }
};
