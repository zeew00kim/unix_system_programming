#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

// 1. 외부 loop에서 현재 인덱스 위치의 값을 key 값으로 지정
// 2. 내부 loop의 인덱스 j의 초기 값은 i - 1
// 3. arr[j]가 key 값보다 큰 동안 arr[j + 1] = arr[j]와 같이 기존 값들을 한 칸씩 back
// 4. 내부 loop 반복 종료 후 key보다 작은 값 바로 다음 인덱스 위치에 key값을 대입
// 위 과정을 정렬이 될 때까지 반복하며 시간복잡도는 O(n^2)
auto insertionSort(vector<int>& v) -> void {
    for (int i = 1; i < v.size(); i++) {
        int key = v.at(i);
        int j = i - 1;
        while (j >= 0 && v.at(j) > key) {
            v.at(j + 1) = v.at(j);
            j--;
        }
        v.at(++j) = key;
    }
}

int main() {

    int size;
    srand(time(nullptr));

    cout << "enter the size of vector : ";
    cin >> size;

    vector<int> arr(size);

    for (int i = 0; i < arr.size(); i++) {
        arr.at(i) = rand() % 20 + 1;
    }

    insertionSort(arr);

    for (int data : arr) { cout << data << " "; }
    cout << endl;

    return 0;
}