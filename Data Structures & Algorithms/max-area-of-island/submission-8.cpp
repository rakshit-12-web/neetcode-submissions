class Solution {
public:
bool valid(int i,int j,int n,int m){

    return i>=0&&j>=0&&i<n&&j<m;

}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int maxi=0;
        vector<vector<int>>visited(n,vector<int>(m,0));

           queue<pair<int,int>>q;

             int area;
                for(int i=0;i<n;i++){
                   for(int j=0;j<m;j++){
           area=0;
                      if(visited[i][j]==0&&grid[i][j]==1){//5
                          area=1;
                         q.push({i,j});
                         visited[i][j]=1;
                           while(!q.empty()){//4
                           int x=q.front().first;
                           int y=q.front().second;
                           q.pop();
                           
                            int row[4]={0,0,1,-1};
                            int col[4]={1,-1,0,0};
                            for(int k=0;k<4;k++){//3

                                int newx=x+row[k];
                                int newy=y+col[k];

                                if(valid(newx,newy,n,m)&&visited[newx][newy]==0){//2
                                    if(grid[newx][newy]==1){//1
                                    visited[newx][newy]=1;
                                     q.push({newx,newy});
                                      area++;
                    
                                    }//1
                                }//2
                              }//3
                          }//4
                }//5
                 maxi=max(maxi,area);
            }
        }
        
            return maxi!=0?maxi:0;
        
        
    }
};
