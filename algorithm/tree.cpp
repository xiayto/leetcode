// 二叉树的定义
struct TreeNode{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x):val(x), left(NULL), right(NULL){}
};

// 二叉树的深度遍历
void traversal(TreeNode *node){
  visit(); //前序遍历
  traversal(node->left);
  visit(); //中序遍历
  traversal(node->right);
  visit(); //后序遍历
}

// leetcode 236 最小公共祖先
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
using namespace std;
void preorder(TreeNode *node, TreeNode *search, vector<TreeNode*> &path, vector<TreeNode*> &result, int &finish){
    if(!node || finish)
        return;
    path.push_back(node);
    if(node == search){
        finish = 1;
        result = path;
    }
    preorder(node->left, search, path, result, finish);
    preorder(node->right, search, path, result, finish);
    path.pop_back();
}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path, result_p, result_q;
        int finish = 0;
        preorder(root, p, path, result_p, finish);
        finish = 0;
        path.clear();
        preorder(root, q, path, result_q, finish);
        int len;
        if(result_p.size() > result_q.size())
            len = result_q.size();
        else
            len = result_p.size();
        TreeNode* res;
        for(int i=0; i<len; i++){
            if(result_p[i] == result_q[i]){
                res = result_p[i];
            }
        }
        return res;
    }
};
//----------------------------------------------------------------------------------------
// 二叉树的层次遍历
void BFS(TreeNode *root){
  queue<TreeNode*> Q;
  Q.push(root);
  while(!Q.empty()){
    TreeNode* node = Q.front();
    Q.pop();
    visit(node);
    if(node->left)
      Q.push(node->left);
    if(node->right)
      Q.push(node->right);
  }
}
// leetcode 199 从右看二叉树
# include<queue>
# include<vector>
using namespace std;


class Solution {
public:
    vector<int> rightSideView(TreeNode* root){
        vector<int> res;
        queue<pair<TreeNode*, int>> Q;
        if(root){
            res.push_back(root->val);
            Q.push(make_pair(root, 0));
        }
        int depth = 0;
        TreeNode* tmp;
        while(!Q.empty()){
            tmp = Q.front().first;
            depth = Q.front().second;
            Q.pop();
            if(depth == res.size()){
                res.push_back(tmp->val);
            }else{
                res[depth] = tmp->val;
            }
            if(tmp->left)
                Q.push(make_pair(tmp->left, depth+1));
            if(tmp->right)
                Q.push(make_pair(tmp->right, depth+1));
        }
        return res;
    }
};
//----------------------------------------------------------------------------------------
