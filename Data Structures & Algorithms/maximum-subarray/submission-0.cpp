class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maxi=0;
        vector<int>prefix(nums.size());
        for(int i=0;i<nums.size();i++){
            
            sum+=nums[i];
            prefix[i]=sum;
            if(sum<0){
                sum=0;
            }
            maxi=max(maxi,sum);
        }
        int k=*max_element(prefix.begin(),prefix.end());
        return k<0?k:maxi;

    }
};
