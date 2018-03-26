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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if(inorder.size() == 0 || inorder.size() != postorder.size())
            return nullptr;
        int n =inorder.size();
        TreeNode* resHead = build(inorder, postorder, 0, n-1, 0, n-1);
        return resHead;
    }
    
    TreeNode* build(vector<int> inorder, vector<int> postorder, int l1, int r1, int l2, int r2){
        if(l1 > r1)
            return nullptr;
        if(l2 > r2)
            return nullptr;
        TreeNode *temp = new TreeNode(postorder[r2]);
        int cnt = 0, index = l1;
        for(; inorder[index] != postorder[r2] && index < r1; index++, cnt++);
        temp->left = build(inorder, postorder, l1, index-1, l2, l2+cnt-1);
        temp->right = build(inorder, postorder, index+1, r1, l2+cnt, r2 - 1);
        return temp;
    }
};
