class Solution {
public:
int solve(int node, vector<int>&path,  vector<vector<int>>&adj){
    if(path[node]==1){
        return true;
    }
    path[node]=1;
    
    for(int j=0;j<adj[node].size();j++){
        if(solve(adj[node][j],path,adj)){
            return true;
        }
    }
path[node]=0;
return 0;
}
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<vector<int>>adj(n);
        for(auto& edge:p){
            int u=edge[0];
            int v=edge[1];
            adj[v].push_back(u);
        }
        vector<int>path(n,0);
        for(int i=0;i<n;i++){
            if(solve(i,path,adj)){
                return false;
            }

        }


     return true;   
    }
};
