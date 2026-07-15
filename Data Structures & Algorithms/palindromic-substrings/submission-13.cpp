class Solution {
public:
bool isPalindrome(string&s,int i,int j){
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int solve(string&s,int i,int j,vector<vector<int>>&dp){

     int n = s.size();
     


        if (i == n){
            return 0;
        }

        if (j == n){
            return solve(s, i + 1, i + 1,dp);
        }

     if(dp[i][j]!=-1){
        return dp[i][j];
      }

        int count = isPalindrome(s, i, j);

        return dp[i][j]=count + solve(s, i, j + 1,dp);
}
    int countSubstrings(string s) {
        if((s.size()==1)){
            return 1;
        }
        vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,-1));
  return   solve(s,0,0,dp);
  
        
         
    }
};
