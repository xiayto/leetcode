// 由先进后出实现先进先出，push到s1中，pop的时候s2中有值就直接pop，无值就把s1中的全部压入s2中

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        int popVal;
        if(!stack2.empty()){
            popVal = stack2.top();
            stack2.pop();
        }
        else{
            while(!stack1.empty()){
                int tmpVal = stack1.top();
                stack1.pop();
                stack2.push(tmpVal);
            }
            popVal = stack2.top();
            stack2.pop();
        }
        return popVal;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
