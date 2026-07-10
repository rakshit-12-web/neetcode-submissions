class Solution {
public:
    bool solve(int i, int j, vector<vector<char>>& board, string &word, int idx) {

        if (idx == word.size())
            return true;

        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() ||
            board[i][j] != word[idx])
            return false;

        char ch = board[i][j];
        board[i][j] = '#'; 

        bool found = solve(i + 1, j, board, word, idx + 1) ||
                     solve(i - 1, j, board, word, idx + 1) ||
                     solve(i, j + 1, board, word, idx + 1) ||
                     solve(i, j - 1, board, word, idx + 1);

        board[i][j] = ch; 

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (solve(i, j, board, word, 0))
                    return true;
            }
        }

        return false;
    }
};