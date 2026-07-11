class Solution {
public:
    vector<vector<string>> ans;

    bool valid(int row, int col, vector<string>& visited) {
        int n = visited.size();

        // Check row and column
        for (int i = 0; i < n; i++) {
            if (visited[row][i] == 'Q')
                return false;
            if (visited[i][col] == 'Q')
                return false;
        }

        // Upper-left diagonal
        int a = row, b = col;
        while (a >= 0 && b >= 0) {
            if (visited[a][b] == 'Q')
                return false;
            a--;
            b--;
        }

        // Lower-left diagonal
        int c = row, d = col;
        while (c < n && d >= 0) {
            if (visited[c][d] == 'Q')
                return false;
            c++;
            d--;
        }

        // Upper-right diagonal
        int e = row, f = col;
        while (e >= 0 && f < n) {
            if (visited[e][f] == 'Q')
                return false;
            e--;
            f++;
        }

        // Lower-right diagonal
        int g = row, h = col;
        while (g < n && h < n) {
            if (visited[g][h] == 'Q')
                return false;
            g++;
            h++;
        }

        return true;
    }

    void solve(int row, vector<string>& visited, int n) {

        if (row == n) {
            ans.push_back(visited);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (valid(row, col, visited)) {
                visited[row][col] = 'Q';
                solve(row + 1, visited, n);
                visited[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<string> visited(n, string(n, '.'));

        solve(0, visited, n);

        return ans;
    }
};