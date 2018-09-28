/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/

// 二叉树的先序遍历

class Solution {
public:
    void Mirror(TreeNode *pRoot){
        if(pRoot == nullptr)
            return;
        if(pRoot->left == nullptr && pRoot->right == nullptr)
            return;
        
        TreeNode *tmp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = tmp;
        
        if(pRoot->left)
            Mirror(pRoot->left);
        if(pRoot->right)
            Mirror(pRoot->right);
    }
};
