#include <iostream>
#include <array>
#include <algorithm>
#include <ctime>
#define NUM 10
using namespace std;

int main() {

    srand(time(nullptr));

    array<int, NUM> arr;
    int idx = 0;

    for (auto it = arr.begin(); it != arr.end(); it++) {
        arr.at(idx++) = rand() % 20 + 1; // array 인덱스의 원소 값을 수정
        cout << *it << " ";
    }
    cout << endl;

    sort(arr.begin(), arr.end()); // 오름차순 정렬

    cout << "value of number 0 idx -> " << arr.front() << endl; // 첫 번째 인덱스에 위치한 값
    cout << "value of last idx number -> " << arr.back() << endl; // 마지막 인덱스에 위치한 값

    auto it = max_element(arr.begin(), arr.end()); // array의 원소 중 최대 값을 반환
    cout << "max value in array -> " << *it << endl;
    it = min_element(arr.begin(), arr.end()); // array의 원소 중 최소 값을 반환
    cout << "min value in array -> " << *it << endl;

    return 0;
}