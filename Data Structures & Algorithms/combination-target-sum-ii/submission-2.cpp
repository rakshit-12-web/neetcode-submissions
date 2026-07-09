class Solution {
public:
    void solve(vector<vector<int>>& ans,
               vector<int>& temp,
               vector<int>& nums,
               int target,
               int i)
    {

        if(target == 0){
            ans.push_back(temp);
            return;
        }
        if(i == nums.size() || target < 0){

            return;
        }
        

      for(int j=i;j<nums.size();j++){
    if(j>i&&nums[j-1]==nums[j]){
        continue;
    }

        temp.push_back(nums[j]);
        solve(ans, temp, nums, target - nums[j], j+1);
        temp.pop_back();

      }
       
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
       vector<vector<int>>ans;
        vector<int>temp;
        sort(nums.begin(),nums.end());
        solve(ans,temp,nums,target,0);
      return ans;
    }
};
