/**

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
 

Example:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.

**/

#include <bits/stdc++.h>

using namespace std;


class MinStack {
	vector<int> stack;
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        stack.push_back(x);
    }
    
    void pop() {
		stack.pop_back();
    }
    
    int top() {
		return stack.back();
    }
    
    int getMin() {
		int min_val = INT_MAX;
		for(auto a: stack){
			if (min_val > a){
				min_val = a;
			}
		}
		
		return min_val;
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


int main()
{
	MinStack minStack;
	minStack.push(-2);
	minStack.push(0);
	minStack.push(-3);
	cout<<minStack.getMin()<<endl;  // --> Returns -3.
	minStack.pop();
	cout<<minStack.top()<<endl;   //   --> Returns 0.
	cout<<minStack.getMin()<<endl;//   --> Returns -2.
	
	return 0;
}
