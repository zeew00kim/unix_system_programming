#include <iostream>
#include <ctime>
using namespace std;

// 랜덤으로 생성된 정수가 약수로 자기 자신과 1만 갖는 소수인지 판단하는 함수
auto isPrimeNumber(int num) -> bool {
    if (num != 1) {
        int divCnt = 0;
        for (int i = 2; i <= num; i++) {
            if (num % i == 0) { divCnt++; }
            if (divCnt >= 2 && num % i == 0) { return false; }
        }
        return true;
    }
    return false;
}

int main() {

    srand(time(nullptr));

    int num = rand() % 30 + 1;;
    
    if (isPrimeNumber(num)) { cout << num << " is prime number" << endl; }
    else { cout << num  << " is not prime number" << endl; }

    return 0;
}