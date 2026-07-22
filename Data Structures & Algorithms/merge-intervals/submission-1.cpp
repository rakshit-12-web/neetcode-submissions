class Solution {
public:
vector<int>mergeTWO(vector<int>&curr,vector<int>&cur){
    int i=curr[0];
    int j=curr[1];
    int i2=cur[0];
    int j2=cur[1];
    if(j>=i2){
        return {min(i,i2),max(j,j2)};
    }
    return {-1,-1};
}
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        vector<int>curr=intervals[0];
        for(int i=1;i<intervals.size();i++){        
       vector<int>temp=mergeTWO(curr,intervals[i]);
       if(temp[0]==-1){
        ans.push_back(curr);
        curr=intervals[i];
       }
       else{
        curr=temp;
       }
        }
        ans.push_back(curr);
        return ans;        
    }
};
