class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
         vector<vector<int>>adj(n);
        for(auto& edge:p){
            int u=edge[0];
            int v=edge[1];
            adj[v].push_back(u);
        }
        vector<int>indegree(n,0);
        queue<int>q;
        vector<int>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<adj[i].size();j++){
                  indegree[adj[i][j]]++;
            }
        }
          for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
            while(!q.empty()){
                int node=q.front();
                q.pop();
             ans.push_back(node);
                for(int j=0;j<adj[node].size();j++){
                    indegree[adj[node][j]]--;
                    if(indegree[adj[node][j]]==0){
                        q.push(adj[node][j]);
                    }
                }
            }
          
          for(int i=0;i<n;i++){
            if(indegree[i]!=0){
                return{};
            }
          }      
          return ans;
    }
};
