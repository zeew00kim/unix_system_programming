#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
using namespace std;

class Zeew00 {
    int age;
    string major;
public:
    Zeew00(const int& age, const string& major) : age{age}, major{major} {}
    auto print_infor() -> void {
        cout << "His Age : " << age << ", Major : " << major << endl;
    }
};

int main() {

    // 동적 할당 Heap에 생성된 객체를 소유 (delete ptr01 불필요)
    unique_ptr<Zeew00> ptr01(new Zeew00(25, "CE")); // 메인 함수 스코프 벗어날 시 메모리 반납
    ptr01->print_infor(); // ptr01은 포인터 변수라 맴버 접근 연산자는 (->)

    unique_ptr<Zeew00> ptr02 = make_unique<Zeew00>(25, "S/W"); // 함수 객체 생성과 메모리 할당을 하나의 연산으로 수행

    // ptr02 객체를 R-value로 만들어 모든 소유권을 ptr03 객체에게 이전
    unique_ptr<Zeew00> ptr03 = move(ptr02); // 이후 ptr02 객체는 사용이 불가능 (없어졌다고 보면 됨)
    ptr03->print_infor();

    // 아래의 로직은 커널에서 OS 규칙을 준수해 SIGSEGV 시그널을 보내 강제 종료
    ptr02->print_infor(); // 소유권 이전 후 할당되지 않은 메모리 접근으로 인한 segmentaion fault 에러 발생

    return 0;
}