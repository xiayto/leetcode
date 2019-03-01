class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || head == nullptr)
            return head;
        int cnt = 1;
        ListNode* p = head;
        while(p->next != nullptr){
            p = p->next;
            cnt++;
        }
        // 注意K的大小可能
        k = k % cnt;
        if(k == 0)
            return head;
        // 可以变为循环链表再拆开
        p->next = head;
        int move = cnt - k;
        while(move){
            head = head->next;
            p = p->next;
            move--;
        }
        p->next = nullptr;
        return head;
    }
};
