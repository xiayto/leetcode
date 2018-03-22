/*
题目要求不用递归解，可以利用栈的结构去解题。
用指针遍历链表，遍历时将节点压入
1 左节点不空一直压入左节点
2 当指针指向了空节点证明当前栈顶的左边已经全部处理完，则弹出栈顶，处理栈顶数据。
3 将指针指向栈顶节点的右子树。
*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* p = root;
        vector<int> res;
        stack<TreeNode*> nodeStack;
        while(p != nullptr || !nodeStack.empty()){
            if(p != nullptr){
                nodeStack.push(p);
                p = p->left;
            }else{
                p = nodeStack.top();
                res.push_back(p->val);
                nodeStack.pop();
                p = p->right;
            }
        }
        return res;
    }
};
