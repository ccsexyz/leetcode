// https://leetcode.com/problems/implement-queue-using-stacks/

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        sa.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        peek();
        sb.pop();
    }

    // Get the front element.
    int peek(void) {
        if(sb.empty()) {
            while(!sa.empty()) {
                sb.push(sa.top());
                sa.pop();
            }
        }
        return sb.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return sa.empty() && sb.empty();
    }
private:
    stack<int> sa, sb;
};
