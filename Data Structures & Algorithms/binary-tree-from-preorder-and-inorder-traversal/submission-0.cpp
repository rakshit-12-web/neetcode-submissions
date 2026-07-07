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
int find(vector<int> inorder,int element){
    for(int i=0;i<inorder.size();i++){
        if(inorder[i]==element){
            return i;
        }
    }
    return -1;
}
TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int&index,int start,int end){
    if(index>=preorder.size()||start>end){
        return NULL;
    }
    int element=preorder[index++];
TreeNode * root=new TreeNode(element);
    int position=find(inorder,element);
    root->left=solve(preorder,inorder,index,start,position-1);
    root->right=solve(preorder,inorder,index,position+1,end);
    return root;

}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        int idx=0;
        return solve(preorder,inorder,idx,0,n-1);
        
    }
};
