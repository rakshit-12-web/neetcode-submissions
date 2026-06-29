class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>s;

        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++){
            int left=i+1;
            int right=nums.size()-1;
            while(left<right){
                int sum=nums[left]+nums[right]+nums[i];
                if(sum==0){
                    s.insert({nums[left],nums[right],nums[i]});
                    right--;
                    left++;
                }
                else if(sum<0){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        vector<vector<int>>ans;
        for(auto x:s){
            ans.push_back({x});
        }
        return ans;
    }
};
