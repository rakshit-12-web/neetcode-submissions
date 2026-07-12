class Solution {
public:
bool valid(int i,int j,int m,int n){
    return i>=0&&j>=0&&i<n&&j<m;

}
    void solve(vector<vector<char>>& board) {
        queue<pair<int,int>>q;
        int n=board.size();
        int m=board[0].size();
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0||j==0||i==n-1||j==m-1){
                if(board[i][j]=='O'){
                    q.push({i,j});
                    board[i][j]='U';
                }
            }
        }
       }

       while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();

        int row[4]={0,0,-1,1};
        int col[4]={1,-1,0,0};
        for(int k=0;k<4;k++){
            int newx=x+row[k];
            int newy=y+col[k];

            if(valid(newx,newy,m,n)&&board[newx][newy]=='O'){
                q.push({newx,newy});
                board[newx][newy]='U';
            }
        }
       }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='U'){
                    board[i][j]='O';
                }
                else{
                    board[i][j]='X';
                }
            }
        }

    }
};
