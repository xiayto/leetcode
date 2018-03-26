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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = preorder.size();
        if(n == 0)
            return nullptr;
        TreeNode *res = build(preorder, inorder, 0, n-1, 0, n-1);
        return res;
    }
    
    TreeNode* build(vector<int> &preorder, vector<int> &inorder, int l1, int r1, int l2, int r2){
        if(l1 > r1)
            return nullptr;
        if(l2 > r2)
            return nullptr;
        TreeNode *temp = new TreeNode(preorder[l1]);
        int i = l2, cnt = 0;
        for(;preorder[l1] != inorder[i]; i++, cnt++);
        temp->left = build(preorder, inorder, l1+1, l1+cnt, l2, i-1);
        temp->right = build(preorder, inorder, l1+cnt+1, r1, i+1, r2);
        return temp;
    }
};
