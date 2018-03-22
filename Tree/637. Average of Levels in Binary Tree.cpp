/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 考察的是二叉树的层次遍历，用队列储存数据，用nextLayerNumber记录下一层的节点数。

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> nodeQueue;
        vector<double> res;
        int nextLayerNumber = 0, curLayerNumber = 1;
        nodeQueue.push(root);
        int i = 0, count = 0;
        double curSum = 0.;
        while(!nodeQueue.empty()){
            while(i < curLayerNumber){
                i++;
                curSum += nodeQueue.front()->val;
                count ++;
                if(nodeQueue.front()->left != nullptr){
                    nodeQueue.push(nodeQueue.front()->left);
                    nextLayerNumber ++;
                }
                if(nodeQueue.front()->right != nullptr){
                    nodeQueue.push(nodeQueue.front()->right);
                    nextLayerNumber ++;
                }
                nodeQueue.pop();
            }
            res.push_back(curSum / count);
            count = 0;
            curSum = 0;
            curLayerNumber = nextLayerNumber;
            nextLayerNumber = 0;
            i = 0;
        }
        return res;
    }
};
