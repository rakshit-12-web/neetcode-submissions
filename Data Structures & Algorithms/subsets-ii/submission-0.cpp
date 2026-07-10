class Solution {
public:
void solve(vector<vector<int>>&ans,vector<int>&nums,int i,vector<int>&temp){
    if(i>=nums.size()){
        ans.push_back(temp);
        return;
    }
  temp.push_back(nums[i]);
  solve(ans,nums,i+1,temp);
  temp.pop_back();
  solve(ans,nums,i+1,temp);
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         vector<vector<int>>ans;
        vector<int>temp;
        sort(nums.begin(),nums.end());
        solve(ans,nums,0,temp);
        set<vector<int>>s;
        for(int i=0;i<ans.size();i++){
            s.insert(ans[i]);;
        }
        return vector<vector<int>>(s.begin(),s.end());
    }
};
