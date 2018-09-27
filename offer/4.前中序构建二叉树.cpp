class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.empty() || vin.empty()){
            return NULL;
        }
        //运用递归的思想，reConstructBinaryTree方法可以建立一棵二叉树，返回根节点
        //先建立根节点，做好左右子树的前中序遍历数组，递归的放入，让根节点指向返回值。
        TreeNode* root = new TreeNode(pre[0]); //前序遍历的第一个是根节点
        vector<int> left_pre, left_vin, right_pre, right_vin;
        int pos = 0;
        for(pos = 0; pos < pre.size(); pos++){
            if(vin[pos] == pre[0])
                break;
        }
        for(int i = 0; i < pos; i++){
            left_pre.push_back(pre[i + 1]);
            left_vin.push_back(vin[i]);
        }
        for(int j = pos + 1; j < pre.size(); j++){
            right_pre.push_back(pre[j]);
            right_vin.push_back(vin[j]);
        }
        root->left = reConstructBinaryTree(left_pre, left_vin);
        root->right = reConstructBinaryTree(right_pre, right_vin);
        return root;
    }
};
