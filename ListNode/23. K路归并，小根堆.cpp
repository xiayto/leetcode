/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<queue>
#include<vector>
using namespace std;

class Solution {
public:
    struct cmp{
        bool operator() (ListNode* l1, ListNode* l2){
            return l1->val > l2->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return nullptr;
        if(lists.size() == 1)
            return lists[0];
        ListNode* dummyHead = new ListNode(0);
        ListNode* dummyHeadP = dummyHead;
        priority_queue<ListNode*, vector<ListNode*>, cmp> smallHeap;
        for(int i = 0; i < lists.size(); i++){
            if(lists[i]) smallHeap.push(lists[i]);
        }
        while(!smallHeap.empty()){
            ListNode* tmp = smallHeap.top();
            smallHeap.pop();
            if(tmp->next)
                smallHeap.push(tmp->next);
            dummyHeadP->next = tmp;
            dummyHeadP = tmp;
        }
        return dummyHead->next;
    }
};
