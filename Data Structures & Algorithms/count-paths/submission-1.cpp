class Solution {
public:

int solve(int i,int j,vector<vector<int>>&path,int m,int n,vector<vector<int>>&dp){
      if(i==m-1&&j==n-1){
       return dp[i][j]=1;
    }
    if(i<0||j<0||i>=m||j>=n){
        return dp[i][j]=0;
    }
  if(dp[i][j]!=-1)
{
    return dp[i][j];
}  

        int row=solve(i+1,j,path,m,n,dp);
        int col=solve(i,j+1,path,m,n,dp);
    

    return dp[i][j]=row+col;
}
    int uniquePaths(int m, int n) {
        vector<vector<int>>path(m,vector<int>(n,0));
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(0,0,path,m,n,dp);
        
        
    }
};
