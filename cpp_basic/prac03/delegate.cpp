#include <iostream>
using namespace std;

class Point {
    int x, y;
public:
    Point();
    Point(int a, int b);
    void show();
};

Point::Point() : Point{10, 20} {}
Point::Point(int x, int y) : x{x}, y{y} {}
auto Point::show() -> void { cout << "point of x : " << x << ", y : " << y << endl; } 

int main() {

    Point point;

    point.show();
    
    return 0;
}