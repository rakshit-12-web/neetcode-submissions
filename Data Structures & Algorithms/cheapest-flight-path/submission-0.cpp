#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Step 1: Adjacency list banana (Jaise aapne banaya tha, auto& use karke)
        vector<vector<pair<int, int>>> adj(n);
        for (auto &edge : flights) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        // Step 2: Distance array initialize karna INT_MAX se
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // Step 3: Queue for BFS -> {stops, {node, current_cost}}
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            // Agar stops K se zyada ho gaye, toh aage explore nahi karenge
            if (stops > k) continue;

            // Neighbors ko check karo
            for (auto &child : adj[node]) {
                int nextNode = child.first;
                int weight = child.second;

                // Agar hume is node tak aane ka aur sasta raasta milta hai
                if (cost + weight < dist[nextNode]) {
                    dist[nextNode] = cost + weight;
                    q.push({stops + 1, {nextNode, dist[nextNode]}});
                }
            }
        }

        // Agar destination tak ka distance badla hi nahi, matlab unreachable hai
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};