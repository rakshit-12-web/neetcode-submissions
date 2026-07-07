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
    vector<int> rightSideView(TreeNode* root) {
         if(root==NULL){
            return {};
        }
        vector<int>a;
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
          int size=q.size();
          vector<int>t;
          for(int i=0;i<size;i++){
            TreeNode* r=q.front();
            q.pop();
            t.push_back(r->val);
             if(r->right){
                q.push(r->right);
            }
              if(r->left){
                q.push(r->left);
            }
           
          }
          ans.push_back(t);
        }
     for(int i=0;i<ans.size();i++){
        a.push_back(ans[i][0]);
     }
     return a;
        
    }
};
