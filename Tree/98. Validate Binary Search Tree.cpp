/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 验证二叉搜索树，中序遍历

class Solution {
public:
    TreeNode *pre = nullptr;
    bool res = true;
    bool isValidBST(TreeNode *root) {
        if(!root)
            return true;
        inorder(root);
        return res;
    }
    
    void inorder(TreeNode *root){
        if(root->left)
            inorder(root->left);
        if(!pre)
            pre = root;
        else if(pre->val >= root->val)
        {
            res = false;
            return;
        }
        pre = root;
        if(root->right)
            inorder(root->right);
    }
};
