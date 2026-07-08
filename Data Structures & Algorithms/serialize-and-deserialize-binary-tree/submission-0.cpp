/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
  
   string serialize(TreeNode* root) {

    if(root == NULL) {
        return "";
    }

    string ans = "";

    queue<TreeNode*> q;

    q.push(root);

    while(!q.empty()) {

        TreeNode* temp = q.front();
        q.pop();

        if(temp == NULL) {

            ans += "N ";

            continue;
        }

        ans += to_string(temp->val) + " ";

        q.push(temp->left);
        q.push(temp->right);
    }

    return ans;
}
   TreeNode* deserialize(string data) {

    if(data.size() == 0) {
        return NULL;
    }

    stringstream ss(data);

    string str;

    ss >> str;

    TreeNode* root =
        new TreeNode(stoi(str));

    queue<TreeNode*> q;

    q.push(root);

    while(!q.empty()) {

        TreeNode* temp = q.front();
        q.pop();

        // LEFT CHILD
        ss >> str;

        if(str != "N") {

            TreeNode* leftNode =
                new TreeNode(stoi(str));

            temp->left = leftNode;

            q.push(leftNode);
        }

        // RIGHT CHILD
        ss >> str;

        if(str != "N") {

            TreeNode* rightNode =
                new TreeNode(stoi(str));

            temp->right = rightNode;

            q.push(rightNode);
        }
    }

    return root;
}
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));