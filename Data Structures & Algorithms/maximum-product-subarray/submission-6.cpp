class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            int mul=1;
            for(int j=i;j<nums.size();j++){
                mul*=nums[j];
                maxi=max(mul,maxi);
            }
            
        }
        return maxi;
    }
};
