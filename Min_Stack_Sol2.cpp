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
	struct node{
		long val;
		long min_val;
		node(long x, long y){
			val = x;
			min_val = y;
		}
		
	};
	vector<struct node> stack;
	int min_val;
public:
    /** initialize your data structure here. */
    MinStack() {
		min_val = INT_MAX;
    }
    
    void push(int x) {
		cout<<"push "<<x<<endl;
		if (min_val > x) {
			stack.emplace_back (x, x);
			min_val = x;
		} else {
			stack.emplace_back (x, min_val);
		}
			
    }
    
    void pop() {
		stack.pop_back();
		cout<<"pop"<<endl;
		if (!stack.empty()) {
			struct node temp1 = stack.back();
			min_val = temp1.min_val;
		}else {
			min_val = INT_MAX;
		}
    }
    
    int top() {
		struct node temp = stack.back();
		return temp.val;
    }
    
    int getMin() {
		struct node temp = stack.back();
		return temp.min_val;
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
	push(-2);
	minStack.push(0);
	minStack.push(-3);
	cout<<minStack.getMin()<<endl;  // --> Returns -3.
	minStack.pop();
	cout<<minStack.top()<<endl;   //   --> Returns 0.
	cout<<minStack.getMin()<<endl;//   --> Returns -2.
	return 0;
}
