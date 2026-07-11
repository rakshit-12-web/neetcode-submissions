class Solution {
public:
bool valid(int i,int j,int n,int m){
    return i>=0&&j>=0&&i<n&&j<m;
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                    grid[i][j]=0;
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
   
    if(valid(newx,newy,n,m)&&grid[newx][newy]==INT_MAX){
        if(grid[x][y]+1<grid[newx][newy]){
            grid[newx][newy]=grid[x][y]+1;
            q.push({newx,newy});
        }
    }
   }

        }      
    }
};
