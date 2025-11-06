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
        if (swapCnt == 0) break; // 이걸 해도 시간 복잡도는 O(n^2)
    }
}