#include <iostream>
#include <array>
#include <memory>
#include <algorithm>
using namespace std;

class Shape {
    int value;
public:
    Shape(int value) : value{value} {}
    auto print() -> void {
        cout << "value : " << value << endl;
    }
};

int main() {

    array<int, 10> a = {1, 2, 3, 4, 5};

    for (int data : a) {
        cout << data << " ";
    }
    cout << endl;

    unique_ptr<Shape> shape(new Shape(10));
    shape->print();

    unique_ptr<Shape> shape02 = make_unique<Shape>(10);
    shape02->print();

    unique_ptr<Shape> shape03 = move(shape02);
    shape03->print();

    return 0;
}