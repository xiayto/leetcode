/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        // 注意特殊的输入
        if(pListHead == nullptr || k == 0)
            return nullptr;
        ListNode* frontP = pListHead;
        ListNode* rearP = pListHead;
        
        // 链表的数量小于k
        for(int i = 0; i < k - 1; i++){
            if(frontP->next)
                frontP = frontP->next;
            else
                return nullptr;
        }
        
        while(frontP->next){
            frontP = frontP->next;
            rearP = rearP->next;
        }
        
        return rearP;
    }
};
