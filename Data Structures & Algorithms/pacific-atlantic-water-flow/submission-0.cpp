class Solution {
public:
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(int i, int j, vector<vector<int>>& heights,
             vector<vector<bool>>& vis) {

        vis[i][j] = true;

        int n = heights.size();
        int m = heights[0].size();

        for (auto &d : dir) {
            int ni = i + d[0];
            int nj = j + d[1];

            if (ni >= 0 && nj >= 0 && ni < n && nj < m &&
                !vis[ni][nj] &&
                heights[ni][nj] >= heights[i][j]) {

                dfs(ni, nj, heights, vis);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));

        // Pacific
        for (int i = 0; i < n; i++)
            dfs(i, 0, heights, pacific);

        for (int j = 0; j < m; j++)
            dfs(0, j, heights, pacific);

        // Atlantic
        for (int i = 0; i < n; i++)
            dfs(i, m - 1, heights, atlantic);

        for (int j = 0; j < m; j++)
            dfs(n - 1, j, heights, atlantic);

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};