/*
Implement the following operations of a stack using queues.

	push(x) -- Push element x onto stack.
	pop() -- Removes the element on top of the stack.
	top() -- Get the top element.
	empty() -- Return whether the stack is empty.
Notes:
	You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
	Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
	You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).

Update (2015-06-11):

The class name of the Java function had been updated to MyStack instead of Stack.
*/

//用队列实现栈
//至少两个队列才能实现

/*
用两个队列模拟一个堆栈：
队列a和b
（1）取栈顶元素： 返回有元素的队列的首元素
（2）判栈空：若队列a和b均为空则栈空
（3）入栈：a队列当前有元素，b为空（倒过来也一样）则将需要入栈的元素先放b中，然后将a中的元素依次出列并入列倒b中。（保证有一个队列是空的）
（4）出栈：将有元素的队列出列即可。
比如先将1插入队a中 ，现在要将2入栈，则将2插入b总然后将a中的1出列入到b中，b中的元素变为 2 ，1
a为空，现在要压入3 则将3插入a中 ，依次将b中的2 ，1 出列并加入倒a中 ，a中的元素变为 3，2，1 b为空
算法保证在任何时候都有一队列为空
*/

class Stack {
private:
	queue<int> q1;
	queue<int> q2;
public:
	// Push element x onto stack.
	void push(int x) {
		if (q1.empty()) {
			q1.push(x);
			while (!q2.empty()) {
				int tmp = q2.front();
				q2.pop();
				q1.push(tmp);
			}
		} else {
			q2.push(x);
			while (!q1.empty()) {
				int tmp = q1.front();
				q1.pop();
				q2.push(tmp);
			}
			
		}	            
	}
	
	// Removes the element on top of the stack.
	void pop() {
		if (!q1.empty()) {
			q1.pop();
		}
		if (!q2.empty()) {
			q2.pop();
		}
	}

	// Get the top element.
	int top() {
		if (!q1.empty()) {
			return q1.front();
		}           
		if (!q2.empty()) {
			return q2.front();
		}
		
		return 0;
	}

	// Return whether the stack is empty.
	bool empty() {
		return q1.empty() && q2.empty();
	}
};
