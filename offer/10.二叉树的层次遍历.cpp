/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/

// 二叉树的层次遍历
#include<queue>
using namespace std;

class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> resVec;
        queue<TreeNode*> treeQueue;
        if(root == nullptr)
            return resVec;
        else
            treeQueue.push(root);
        while(!treeQueue.empty()){
            TreeNode* tmpNode = treeQueue.front();
            treeQueue.pop();
            resVec.push_back(tmpNode->val);
            if(tmpNode->left)
                treeQueue.push(tmpNode->left);
            if(tmpNode->right)
                treeQueue.push(tmpNode->right);
        }
        return resVec;
    }
};
