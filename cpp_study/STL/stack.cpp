#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
using namespace std;

template <class T>
class Stack {
    int top, size;
    vector<T> stack;
public:
    Stack(int size) : size{size}, top{-1} {
        stack.resize(this->size);
    }
    auto is_full() -> bool { return (top == size - 1) ? true : false; }
    auto is_empty() -> bool { return (top == -1) ? true : false; }
    void push(T element) {
        if (is_full()) { throw runtime_error("stack overflow error"); }
        stack.at(++top) = element;
    }
    T pop() {
        if (is_empty()) { throw runtime_error("stack underfow error"); }
        return stack.at(top--);
    }
    T peek() {
        if (is_empty()) { throw runtime_error("stack underfow error"); }
        return stack.at(top);
    }
};

int main() {

    int size;

    cout << "enter the size of stack -> ";
    cin >> size;

    Stack<int> stack(size);

    while (true) {
        int data, sel;
        cout << "[ 1. push | 2. pop | 3. peek ] --> ";
        cin >> sel;
        if (sel < 1 || sel > 3) break;
        try {
            switch(sel) {
            case 1:
                cout << "enter the push data -> ";
                cin >> data;
                stack.push(data);
                break;
            case 2:
                data = stack.pop();
                cout << "pop data -> " << data << endl;
                break;
            default:
                data = stack.peek();
                cout << "peek data -> " << data << endl;
            }
        }
        catch (runtime_error e) { cout << e.what() << endl; }
    }

    return 0;
}