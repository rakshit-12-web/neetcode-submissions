class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=1;i<nums.size();i++){
            for(int j=i+1;j<=nums.size();j++){
                if(nums[i-1]+nums[j-1]==target){
                    return {i,j};
                }
            }
        }
     return {};   
    }
};
