/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 
 //还原一个二叉搜索树，注意两种情况，一个是相邻两个点交换，一个是不相邻的交换
 
 
class Solution {
public:
    TreeNode *mistake1 = nullptr;
    TreeNode *mistake2 = nullptr;
    TreeNode *pre = nullptr;
    
    void recoverTree(TreeNode* root) {
        inorder(root);
        if(mistake1 && mistake2)
            swap(mistake1->val, mistake2->val);
        return;
    }
    void inorder(TreeNode* root){
        if(!root)
            return;
        if(root->left)
            inorder(root->left);
        if(!pre)
            pre = root;
        else if(pre->val > root->val){
            if(!mistake1){
                mistake1 = pre;
                mistake2 = root;
            }else{
                mistake2 = root;
            }
        }
        pre = root;
        if(root->right)
            inorder(root->right);
        
    }
};
