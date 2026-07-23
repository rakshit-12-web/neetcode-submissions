class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>ans(n,vector<int>(n,1));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
            {
                 ans[j][i]=matrix[i][j];
            }

        }
   

    for (int i = 0; i < ans.size(); i++) {
        reverse(ans[i].begin(), ans[i].end());
}
  for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
            {
                 matrix[i][j]=ans[i][j];
            }

        }
   

        
    }
};
