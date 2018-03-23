/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

// 用队列层次遍历，不满足空间复杂度O(1)的要求
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == nullptr)
            return;
        queue<TreeLinkNode*> treeQ;
        int i = 0, curLayerNum = 1, nextLayerNum = 0;
        treeQ.push(root);
        while(!treeQ.empty()){
            while(i < curLayerNum){
                i++;
                TreeLinkNode* temp = treeQ.front();
                treeQ.pop();
                if(i == curLayerNum)
                    temp->next = nullptr;
                else
                    temp->next = treeQ.front();
                if(temp->left != nullptr){
                    nextLayerNum++;
                    treeQ.push(temp->left);
                }
                if(temp->right != nullptr){
                    nextLayerNum++;
                    treeQ.push(temp->right);
                }
            }
            curLayerNum = nextLayerNum;
            i = 0;
            nextLayerNum = 0;
        }
    }
};


//利用next指针层次遍历
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == nullptr)
            return;
        TreeLinkNode* cur;
        while(root->left != nullptr){
            cur = root;
            while(cur != nullptr){
                cur->left->next = cur->right;
                if(cur->next != nullptr)
                    cur->right->next = cur->next->left;
                cur = cur->next;
            }
            root = root->left;
        }
    }
};
