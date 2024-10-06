#include <iostream>
#include <stdexcept>

class Stack {
private:
    int* arr;
    int top;       
    int capacity;     

public:
    Stack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int x) {
        if (top == capacity - 1) {
            throw std::overflow_error("Stack Overflow: Cannot push onto a full stack.");
        }
        arr[++top] = x; 
    }

    int pop() {
        if (isEmpty()) {
            throw std::underflow_error("Stack Underflow: Cannot pop from an empty stack.");
        }
        return arr[top--];
    }

    bool isEmpty() const {
        return top == -1;
    }

    void display() const {
        if (isEmpty()) {
            std::cout << "Stack is empty." << std::endl;
            return;
        }
        
        std::cout << "Stack elements: ";
        for (int i = top; i >= 0; --i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    int size;

    std::cout << "Enter the size of the stack: ";
    std::cin >> size;

    Stack stack(size);
    
    int choice, value;

    do {
        std::cout << "\n1. Push\n2. Pop\n3. Display\n4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter value to push: ";
                std::cin >> value;
                try {
                    stack.push(value);
                } catch (const std::overflow_error& e) {
                    std::cerr << e.what() << std::endl;
                }
                break;

            case 2:
                try {
                    value = stack.pop();
                    std::cout << "Popped value: " << value << std::endl;
                } catch (const std::underflow_error& e) {
                    std::cerr << e.what() << std::endl;
                }
                break;

            case 3:
                stack.display();
                break;

            case 4:
                std::cout << "Exiting..." << std::endl;
                break;

            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 4);

    return 0;
}