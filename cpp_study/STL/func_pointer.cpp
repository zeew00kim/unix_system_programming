#include <iostream>
#include <cstring>
#include <functional> // invoke() 함수 사용 목적 선언
using namespace std;

class Zeew00 {
    char* major;
public:
    Zeew00(const char* major) {
        int len = strlen(major) + 1;
        this->major = new char[len];
        strcpy(this->major, major);
    }
    ~Zeew00() {
        if (major != nullptr) {
            delete[] major;
        }
    }
    auto print() -> void {
        cout << this->major << endl;
    }
};

void func01(int data) {
    cout << data << endl;
}

int main() {

    void(*f1)(int) = &func01; // 일반 함수 포인터
    f1(10); // 10 출력

    void(*f2)(int) = &func01;
    invoke(f2, 20);

    Zeew00 zeew00("S/W");
    // 객체 함수 포인터 작성 방식 01
    void(Zeew00::*func_z)() = &Zeew00::print;
    zeew00.print();

    // 객체 함수 포인터 작성 방식 02 -> Morden C++17 문법
    void(Zeew00::*func_inv)() = &Zeew00::print;
    invoke(func_inv, &zeew00);

    return 0;
}