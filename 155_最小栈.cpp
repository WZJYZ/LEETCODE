//
// Created by lwj on 2020/5/12.
//
#include <iostream>
#include <stack>

using namespace std;


class MinStack {
private:
    stack<int> data_stack;
    stack<int> min_stack;
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        data_stack.push(x);

        if (min_stack.empty() || x <= min_stack.top())
            min_stack.push(x);
    }

    void pop() {
        if (data_stack.top() == min_stack.top())
            min_stack.pop();
        data_stack.pop();

    }

    int top() {
        return data_stack.top();
    }

    int getMin() {
        return min_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    cout << obj->getMin() << endl;
    cout << obj->top() << endl;
    obj->pop();
    cout << obj->getMin() << endl;
    return 0;
}