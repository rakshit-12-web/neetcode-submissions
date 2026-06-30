class Solution {
public:
int po(int i,int j,vector<int>&nums){
    int maxi=-1;
    for(int k=i;k<=j;k++){
        maxi=max(nums[k],maxi);
    }
    return maxi;
}
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        int i=0;
        int j=0;
        while(j<nums.size()){
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                ans.push_back(po(i,j,nums));
                i++;
                j++;
            }
        }
        return ans;
    }
};
