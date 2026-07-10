class Solution {
public:
   void solve(int i,string temp,int n,vector<string>&ans,int close,int open){
    
 if(i==n*2){
    ans.push_back(temp);
    return;
 } 
if(close<n){
 solve(i+1,temp+'(',n,ans,close+1,open); 
}
 if(close>open){
    solve(i+1,temp+')',n,ans,close,open+1);
 }
    }
    vector<string> generateParenthesis(int n) {
        string temp;
        vector<string>ans;
        int close=0;
        int open=0;
        solve(0,temp,n,ans,close,open);
        return ans;        
    }
};
