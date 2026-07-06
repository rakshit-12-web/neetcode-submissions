/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
void solve(TreeNode*p,vector<int>&ans){
    if(p==NULL){
        ans.push_back(-1);
        return;
    }
    ans.push_back(p->val);
    solve(p->left,ans);
    solve(p->right,ans);
}
    bool isSameTree(TreeNode* p, TreeNode* q) {
          vector<int>p1;
          solve(p,p1);
          vector<int>q1;
          solve(q,q1);
          if(p1.size()!=q1.size()){
            return false;
          }
          for(int i=0;i<p1.size();i++){
            if(p1[i]!=q1[i]){
                return false;
            }
          }
          return true;            
    }
};
