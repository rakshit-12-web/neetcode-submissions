class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int srow=0;
        int scol=0;
        int ecol=matrix[0].size()-1;
        int erow=matrix.size()-1;
        int m=matrix[0].size();
        int n=matrix.size();
        while(srow <= erow && scol <= ecol){
      for(int i=scol;i<=ecol;i++){
       ans.push_back(matrix[srow][i]); 
      }
      srow++;
      for(int i=srow;i<=erow;i++){
        ans.push_back(matrix[i][ecol]);
      }
      ecol--;
       // Bottom row
            if (srow <= erow) {
                for (int i = ecol; i >= scol; i--)
                    ans.push_back(matrix[erow][i]);
                erow--;
            }

            // Left column
            if (scol <= ecol) {
                for (int i = erow; i >= srow; i--)
                    ans.push_back(matrix[i][scol]);
                scol++;
            }
        }          
    return ans;
    }
};
