class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix=1;
        int suffix=1;
        int n=nums.size();
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(prefix==0){
                prefix=1;
            }
              if(suffix==0){
                suffix=1;
            }
            prefix=nums[i]*prefix;
            suffix=nums[n-i-1]*suffix;
            maxi=max(maxi,max(prefix,suffix));

        }
        return maxi;
        
    }
};