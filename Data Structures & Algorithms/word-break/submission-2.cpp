class Solution {
public:
int check(int i,int j,set<string>&se,string &s){
    string word=s.substr(i,j);
    if(se.count(word)){
        return true;
    }
    return false;
}
bool solve(int i,set<string>&se,string&s,vector<int>&dp){
    if(i==s.size()){
        return true;
    }
    if(dp[i]!=-1){
        return dp[i];
    }

for(int j=i;j<s.size();j++){
    if(check(i,j-i+1,se,s)){
   if(solve(j+1,se,s,dp)){
    return true;
   }
    }
}
return dp[i]=false;
}

    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>se;
        for(auto&x:wordDict){
            se.insert(x);
        }
        vector<int>dp(s.size()+1,-1);    
       return solve(0,se,s,dp);
    }
};
