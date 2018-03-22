/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        stack<TreeNode*> nodeStack;
        nodeStack.push(root);
        vector<int> res;
        if(root == nullptr)
            return res;
        while(!nodeStack.empty()){
            TreeNode* temp = nodeStack.top();
            res.push_back(temp->val);
            nodeStack.pop();
            if(temp->right != nullptr)
                nodeStack.push(temp->right);
            if(temp->left != nullptr )
                nodeStack.push(temp->left);
        }
        return res;
    }
};
