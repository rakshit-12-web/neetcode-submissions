class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int count=1;
        int maxi=0;
        if(nums.size()==1){
            return 1;
        }
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();){
          if(nums[i]-nums[i-1]==1){
            count++;
          }
          else if(nums[i]-nums[i-1]!=0){
            count=1;
          }
         maxi=max(count,maxi);
         i++;
        }
return maxi;
        
    }
};
