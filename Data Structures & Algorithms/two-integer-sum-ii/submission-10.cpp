class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int,int>m;
       for(int i=0;i<nums.size();i++){
        int a=target-nums[i];
        if(m.find(a)!=m.end()){
            return{m[a]+1,i+1};
        }
        m[nums[i]]=i;
       }
       return {};
    }
};
