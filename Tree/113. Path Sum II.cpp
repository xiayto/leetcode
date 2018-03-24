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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int>> res;
        vector<int> item;
        pathSumGenerate(root, item, res, sum);
        return res;
    }
    
    void pathSumGenerate(TreeNode* p, vector<int> &item, vector<vector<int>> &res, int sum){
        if(p == nullptr)
            return;
        item.push_back(p->val);
        if(sum - p->val == 0 && !p->left && !p->right)
            res.push_back(item);
        if(p->left != nullptr)
            pathSumGenerate(p->left, item, res, sum - p->val);
        if(p->right != nullptr)
            pathSumGenerate(p->right, item, res, sum - p->val);
        item.pop_back();
        sum = sum + p->val;
    }
};
