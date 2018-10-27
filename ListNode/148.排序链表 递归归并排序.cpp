/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL){}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        // 边界条件的判断，倒推到最小的情况考虑，这里最小的情况是两个节点，如果小于2个节点直接返回。
        if(head == nullptr || head->next == nullptr)
            return head;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow->next;
        slow->next = nullptr;
        
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(fast);
        
        return mergerTwoList(l1, l2);
    }
    
    ListNode* mergerTwoList(ListNode* l1, ListNode* l2){
        ListNode* dummyHead = new ListNode(-1);
        ListNode* p = dummyHead;
        while(l1 != nullptr && l2 != nullptr){
            if(l1->val > l2->val){
                p->next = l2;
                l2 = l2->next;
            }
            else{
                p->next = l1;
                l1 = l1->next;
            }
            p = p->next;
        }
        if(l1 != nullptr)
            p->next = l1;
        if(l2 != nullptr)
            p->next = l2;
        return dummyHead->next;
    }
};
