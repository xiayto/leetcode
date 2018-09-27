// 用栈实现

#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        if(head == nullptr) return res;
        ListNode* p = head;
        stack<int> resStack;
        while(p != nullptr){
            resStack.push(p->val);
            p = p->next;
        }
        while(!resStack.empty()){
            res.push_back(resStack.top());
            resStack.pop();
        }
        return res;
    }
};
