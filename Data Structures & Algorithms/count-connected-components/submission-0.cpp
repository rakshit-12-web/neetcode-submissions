class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
         vector<vector<int>>adj(n);
        for(auto&edge:edges){
             int u=edge[0];
             int v=edge[1];
             adj[u].push_back(v);
             adj[v].push_back(u);
        }
        queue<pair<int,int>>q;
        vector<int>visited(n,0);
    int count=0;
         for(int k=0;k<n;k++){
            if(!visited[k]){
        q.push({k,-1});
        count++;
            }
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
                else if(!visited[neigh])
                {
                    q.push({neigh,node});
                    
                }
        }
        }
        }
        return count;

    }
};
