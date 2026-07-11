class Solution {
public:


bool valid(int i,int j,int n,int m){

    return i>=0&&j>=0&&i<n&&j<m;

}

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;

        vector<vector<int>>visited(n,vector<int>(m,0));

           queue<pair<int,int>>q;


                for(int i=0;i<n;i++){
                   for(int j=0;j<m;j++){
                      
                      if(visited[i][j]==0&&grid[i][j]=='1'){
                        count++;
                         q.push({i,j});
                           while(!q.empty()){
                           int x=q.front().first;
                           int y=q.front().second;
                           q.pop();
                          
                            int row[4]={0,0,1,-1};
                            int col[4]={1,-1,0,0};
                            for(int k=0;k<4;k++){

                                int newx=x+row[k];
                                int newy=y+col[k];

                                if(valid(newx,newy,n,m)&&visited[newx][newy]==0){
                                    if(grid[newx][newy]=='1'){
                                    visited[newx][newy]=1;
                                     q.push({newx,newy});
                                    }
                                }
                              }
                          }

                }

            }
        }
        return count;
    }
};