/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 用迭代的方法后序遍历二叉树
// 与中序遍历不同的是要用一个pre指针记住上一个访问的节点，如果是栈顶的右节点，才弹栈访问

class Solution{
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode*> nodeStack;
        TreeNode* pre = nullptr;
        if(root == nullptr)
            return res;
        while(root != nullptr || !nodeStack.empty())
        {
            if(root != nullptr)
            {
                nodeStack.push(root);
                root = root->left;
            }
            else if(nodeStack.top()->right != pre)
            {
                root = nodeStack.top()->right;
                pre = nullptr;
            }
            else
            {
                res.push_back(nodeStack.top()->val);
                pre = nodeStack.top();
                nodeStack.pop();
            }
        }
        
        return res;
    }
};
