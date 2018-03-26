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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(!p && !q)
            return true;
        if(!p || !q)
            return false;
        if(p->val != q->val)
            return false;
        else
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};


// 非递归解法

public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        queue<TreeNode*> mQ1, mQ2;
        if(!p && !q)
            return true;
        if(!isSameNode(p, q))
            return false;
        mQ1.push(p);
        mQ2.push(q);
        while(!mQ1.empty() && !mQ2.empty()){
            auto node1 = mQ1.front(); mQ1.pop();
            auto node2 = mQ2.front(); mQ2.pop();
            if(!isSameNode(node1->left, node2->left))
                return false;
            else if(node1->left && node2->left){
                mQ1.push(node1->left);
                mQ2.push(node2->left);
            }
            if(!isSameNode(node1->right, node2->right))
                return false;
            else if(node1->right && node2->right){
                mQ1.push(node1->right);
                mQ2.push(node2->right);
            }
        }
        return true;
    }
    
    bool isSameNode(TreeNode *p, TreeNode *q){
        if(!p && !q)
            return true;
        if(!p || !q)
            return false;
        if(p->val != q->val)
            return false;
        else
            return true;
    }
};


