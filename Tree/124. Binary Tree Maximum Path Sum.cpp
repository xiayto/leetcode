class Solution {
public:
    int maxVal = INT_MIN;
    
    int maxPathSum(TreeNode *root) {
        if(root == nullptr)
            return 0;
        maxSum(root);
        return maxVal;
    }
    
    int maxSum(TreeNode* root){
        if(root == nullptr)
            return 0;
        int curVal = root->val;
        int lMax = maxSum(root->left), rMax = maxSum(root->right);
        int curMax = root->val;
        if(lMax > 0)
            curMax += lMax;
        if(rMax > 0)
            curMax += rMax;
        if(curMax > maxVal)
            maxVal = curMax;
        return max(curVal, max(lMax + curVal, rMax + curVal));
    }
};
