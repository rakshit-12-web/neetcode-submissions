class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto&edge:edges){
             int u=edge[0];
             int v=edge[1];
             adj[u].push_back(v);
             adj[v].push_back(u);
        }
        queue<pair<int,int>>q;
        vector<int>visited(n,0);
    
         
        q.push({0,-1});
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            visited[node]=1;
            q.pop();
            for(int j=0;j<adj[node].size();j++){
                int neigh=adj[node][j];
                if(parent==neigh){
                    continue;
                }
                 if(visited[neigh]==1){
                    return false;
                }
                else{
                    q.push({neigh,node});
                    
                }
        }
        }
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                return false;
            }
        }
        
        return true;

    }
};
