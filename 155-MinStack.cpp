//Min Stack 最小栈
/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/

/*
这道最小栈跟原来的栈相比就是多了一个功能，可以返回该栈的最小值。使用两个栈来实现，一个栈来按顺序存储push进来的数据，另一个用来存出现过的最小值。代码如下: 
*/
class MinStack {
public:
	stack<int> stk, minstk;

	void push(int x) {
		stk.push(x);
		if (minstk.empty() || x <= minstk.top())
			minstk.push(x);
	}

	void pop() {
		if (!stk.empty()) {
			int top = stk.top();
			stk.pop();
			if (top == minstk.top())
				minstk.pop();
		}
	}

	int top() {
		if (!stk.empty()) {
			return stk.top();
		}
		return 0;
	}

	int getMin() {
		if (!minstk.empty()) {
			return minstk.top();
		}
		return 0;
	}
};
