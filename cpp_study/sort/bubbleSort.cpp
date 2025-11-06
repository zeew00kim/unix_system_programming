#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

auto bubbleSort(vector<int>&) -> void;

int main() {

    int size, i = 0;
    srand(time(NULL));

    cout << "enter the size of vector -> ";
    cin >> size;

    vector<int> arr(size);

    while (i < size) {
        arr.at(i) = rand() % 20 + 1;
        i++;
    }

    bubbleSort(arr);

    for (int data : arr) {
        cout << data << " ";
    }
    cout << endl;

    return 0;
}

// 가장 큰 값을 배열의 맨 뒤로 보내며 정렬하는 방식
auto bubbleSort(vector<int>& v) -> void {
    for (int i = 0; i < v.size(); i++) {
        int swapCnt = 0;
        for (int j = 0; j < v.size() -i -1; j++) {
            if (v.at(j) > v.at(j + 1)) {
                swap(v.at(j), v.at(j + 1));
                swapCnt++;
            }
        }
        // 그닥 의미는 없지만 더 이상 순회할 필요가 없으니 중단
        // 이미 정렬된 배열이라면 O(n) 아닐 시 O(n^2)
        if (swapCnt == 0) break; 
    }
}