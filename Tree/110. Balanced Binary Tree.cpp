
// 递归检查左右节点的深度，所有节点左右节点深度小于1
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if(!root)
            return true;
        int left_depth = depth(root->left);
        int right_depth = depth(root->right);
        int diff = left_depth - right_depth;
        if(diff > 1 || diff < -1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
    
    int depth(TreeNode *root){
        if(!root)
            return 0;
        int left_depth = depth(root->left);
        int right_depth = depth(root->right);
        return left_depth > right_depth ? left_depth + 1 : right_depth + 1;
    }
};
