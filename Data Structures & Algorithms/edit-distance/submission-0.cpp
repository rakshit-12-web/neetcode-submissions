class Solution {
public:  
int solve(int m,int n,string w1, string w2,vector<vector<int>>&dp){
   if(m < 0) return n + 1;
if(n < 0) return m + 1;
if(dp[m][n]!=-1){
    return dp[m][n];
}
if(w1[m]==w2[n]){
  return dp[m][n]=solve(m-1,n-1,w1,w2,dp);
}
 return dp[m][n]= min({
    1 + solve(m - 1, n, w1, w2,dp),      // delete
    1 + solve(m, n - 1, w1, w2,dp),      // insert
    1 + solve(m - 1, n - 1, w1, w2,dp)   // replace
});
}
    int minDistance(string w1, string w2) {

        vector<vector<int>>dp(w1.length()+1,vector<int>(w2.length()+1,-1));
       return solve(w1.size()-1,w2.size()-1,w1,w2,dp);     
    }
};