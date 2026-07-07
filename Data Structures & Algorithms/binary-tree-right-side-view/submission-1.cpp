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
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
          int size=q.size();
          a.push_back(q.front()->val);
          for(int i=0;i<size;i++){
            TreeNode* r=q.front();
            q.pop();
             if(r->right){
                q.push(r->right);
            }
              if(r->left){
                q.push(r->left);
            }
          }
        }
        return a;
    }
};
