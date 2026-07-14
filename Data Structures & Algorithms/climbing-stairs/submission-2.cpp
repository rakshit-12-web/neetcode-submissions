class Solution {
public:
int solve(int n,vector<int>&t){
    if(t[n]!=-1){
        return t[n];
    }
    if(n==0)
  {
    return t[n]=1;
     }
     if(n==1){
    return t[n]=1;
     }
   
       return t[n]=solve(n-1,t)+solve(n-2,t);
        

}
    int climbStairs(int n) {
       vector<int>t(100,-1);

        return solve(n,t);

  
    }
};
