class Solution {
public:
int solve(int i,vector<int>&cost,vector<int>&t){
    if(t[i]!=-1){
        return t[i];
    }
    if(i>=cost.size()){
        return t[i]=0;
    }
    int s=cost[i]+solve(i+1,cost,t);
    int d=cost[i]+solve(i+2,cost,t);
    return t[i]=min(s,d);
}
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>t(500,-1);

        return min(solve(0,cost,t),solve(1,cost,t));
        
    }
};
