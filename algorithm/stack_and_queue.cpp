#include <stack> 
S.top(); //取出栈顶 
S.empty(); //判断栈是否为空 
S.push(x); //将x压入栈中 
S.pop(); //弹出栈顶 
S.size(); //栈的存储元素个数

// leetcode 例题 155，实现一个能返回最小值的栈
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        _data.push(x);
        if(_min.empty()){
            _min.push(x);
        }else{
            if(_min.top() > x){
                _min.push(x);
            }else{
                _min.push(_min.top());
            }
        }
    }
    
    void pop() {
        _data.pop();
        _min.pop();
    }
    
    int top() {
        return _data.top();
    }
    
    int getMin() {
        return _min.top();
    }
    private:
        stack<int> _data;
        stack<int> _min;
};

#include <queue> 
Q.empty(); //判断队列是否为空 
Q.front(); //返回队列的头部元素 
Q.back(); //返回队列的尾部元素 
Q.pop(); //弹出队列头部元素 
Q.push(x); //将x添加至队列 
Q.size(); //返回队列中的存储元素个数

// 用优先队列实现堆
#include <queue>
#include <vector>
using namespace std;
priority_queue<int> big_heap; // 默认是大顶堆
priority_queue<int, vector<int>, greater<int>> small_heap; //建立小顶堆
// 基本操作：
small_heap.pop();
small_heap.push();
small_heap.top();

// leetcode 例题 215 返回第k大的数，维护一个size为k的小顶堆
# include<iostream>
# include<queue>
# include<vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> small_heap;
        for(int i = 0; i<nums.size(); i++){
            if(small_heap.size() < k){
                small_heap.push(nums[i]);
            }
            else{
                if(small_heap.top() < nums[i]){
                    small_heap.push(nums[i]);
                    small_heap.pop();
                }
            }
        }
        return small_heap.top();
    }
};
