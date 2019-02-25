//用一个vector存数，二分建树，用了O(n)的额外空间

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        while(head != nullptr){
            nums.push_back(head->val);
            head = head->next;
        }
        TreeNode* res = nullptr;
        res = vectorToBST(nums, 0, nums.size() - 1); //注意边界条件，这里-1
        return res;
    }
    
    TreeNode* vectorToBST(vector<int> &nums, int begin, int end){
        if (begin == end){
            return new TreeNode(nums[begin]);
        }
        if (begin > end){
            return nullptr;
        }
        int mid = begin + (end - begin) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = vectorToBST(nums, begin, mid - 1);
        root->right = vectorToBST(nums, mid + 1, end);
        return root;
    }
};

//不需要额外空间的做法
/*
 模拟树的中序遍历递归版。
  */
116ms
class Solution {
public:
    TreeNode *sortedListToBST(ListNode* & head, int start, int end) {
        if (start > end) return NULL;
        int mid = start + (end - start) / 2;
        TreeNode* left = sortedListToBST(head, start, mid - 1);
        TreeNode* parent = new TreeNode(head->val);
        parent->left = left;
        head = head->next;
        TreeNode* right = sortedListToBST(head, mid + 1, end);
        parent->right = right;
        //levelorder_tra(parent);
        return parent;
    }
    
    TreeNode *sortedListToBST(ListNode *head) {
        int length = 0;
        ListNode* node = head;
        while ( node != NULL) {
            length++;
            node = node->next;
        }
        return sortedListToBST(head, 0, length - 1);    
    }
};

