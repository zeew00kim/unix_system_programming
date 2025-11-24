#include <iostream>
#include <cmath>
#include <memory>
using namespace std;

class Circle {
    int radius;
public:
    Circle() {}
    void setRadius(int radius = 5) { this->radius = radius; }
    double getArea() { return 3.14 * pow(radius, 2); }
};

int main() {

    int radius, size;

    cout << "enter the size : ";
    cin >> size;

    unique_ptr<Circle[]> circArr = make_unique<Circle[]>(size); // 스마트 포인터 (메모리 헤제 불필요)

    for (int i = 0; i < size; i++) {
        cout << "enter the radius : ";
        cin >> radius;
        circArr[i].setRadius(radius);
    }

    for (int i = 0; i < size; i++) {
        cout << "Circle no." << i + 1 << "'s size : " << circArr[i].getArea() << endl;
    }

    return 0;
}