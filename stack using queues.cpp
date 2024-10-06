#include <iostream>
#include <queue>

class StackUsingQueues {
private:
    std::queue<int> q1;
    std::queue<int> q2;

public:
    void push(int x) {
        q2.push(x);

        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        std::swap(q1, q2);
    }

    void pop() {
        if (q1.empty()) {
            std::cout << "Stack is empty!" << std::endl;
            return;
        }
        q1.pop();
    }

    int top() {
        if (q1.empty()) {
            std::cout << "Stack is empty!" << std::endl;
            return -1;
        }
        return q1.front();
    }

    bool isEmpty() {
        return q1.empty();
    }
};

int main() {
    StackUsingQueues stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Top element: " << stack.top() << std::endl;

    stack.pop();
    std::cout << "Top element after pop: " << stack.top() << std::endl;

    stack.pop();
    stack.pop();

    if (stack.isEmpty()) {
        std::cout << "Stack is empty!" << std::endl;
    }

    return 0;
}