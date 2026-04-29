// 练习用两个栈实现队列，栈与队列的转换
#include<iostream>
#include<string>
#include<stack>

//232. 用栈实现队列

class MyQueue {
private:
    std::stack<int> inStack;
    std::stack<int> outStack;

    //辅助函数，当outStack为空时，将inStack的元素全部放进outStack

    void transferifempty()
    {
        if(outStack.empty())
        {
            while(!inStack.empty())
            {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
    }
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        inStack.push(x);
    }
    
    int pop() {
        int val = peek();
        outStack.pop();
        return val;
    }
    
    int peek() {
        transferifempty();
        return outStack.top();
    }
    
    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};