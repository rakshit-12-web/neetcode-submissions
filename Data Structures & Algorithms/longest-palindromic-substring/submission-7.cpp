class Solution {
public:

bool check(int i,int j,string s){
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int solve(int i,int j,int&startlen,int&maxlen,string&s,vector<vector<int>>&t){
    if(i>j){
        return 0;
    }
    if(t[i][j]!=-1){
        return t[i][j];
    }
    if(s[i]==s[j]){
        if(check(i,j,s)){
        if(j-i+1>maxlen){
            maxlen=j-i+1;
            startlen=i;
        }
                }
        solve(i+1,j-1,startlen,maxlen,s,t);
    }
    solve(i+1,j,startlen,maxlen,s,t);
    solve(i,j-1,startlen,maxlen,s,t);
    return t[i][j]=0;

}
    string longestPalindrome(string s) {
        if(s.size()==1){
            return s;
        }
       vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,-1));
   
   int start=0;
   int end=0;
    solve(0,s.size()-1,start,end,s,dp);
    return s.substr(start,end);

        
    }
};
