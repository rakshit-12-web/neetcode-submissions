class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto &edge:times){
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            adj[u].push_back({v,w});
        }
        vector<int>dist(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        dist[k]=0;
        q.push({0,k});
        while(!q.empty()){
            int d = q.top().first;
            int node = q.top().second;
            q.pop();

            if(d > dist[node]) continue;
            for(int i=0;i<adj[node].size();i++){
                int neigh=adj[node][i].first;
                int weight=adj[node][i].second;
                if(dist[node]+weight<dist[neigh]){
                    dist[neigh]=dist[node]+weight;
                   
                    q.push({dist[neigh],neigh});
                }

            }
        }
        int ans = 0;

        for(int i=1;i<=n;i++){

            if(dist[i] == INT_MAX)
                return -1;

            ans = max(ans, dist[i]);
        }
        
        return ans;

    }
};
