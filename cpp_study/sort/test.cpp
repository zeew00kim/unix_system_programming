#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

// void bubbleSort(vector<int> &p) {
//     for (int i = 0; i < p.size(); i++) {
//         int swapCnt = 0;
//         for (int j = 0; j < p.size() - i - 1; j++) {
//             if (p.at(j) > p.at(j + 1)) {
//                 int temp = p.at(j);
//                 p.at(j) = p.at(j + 1);
//                 p.at(j + 1) = temp;
//                 swapCnt++;
//             }
//         }
//         if (swapCnt < 1) { break; }
//     }
// }

// void insertionSort(vector<int> &p) {
//     for (int i = 1; i < p.size(); i++) {
//         int key = p.at(i);
//         int j = i - 1;
//         while (j >= 0 && p.at(j) > key) {
//             p.at(j + 1) = p.at(j);
//             j--;
//         }
//         p.at(++j) = key;
//     }
// }

// void selectionSort(vector<int> &p) {
//     for (int i = 0; i < p.size() - 1; i++) {
//         int minIdx = i;
//         for (int j = i + 1; j < p.size(); j++) {
//             minIdx = (p.at(j) < p.at(minIdx)) ? j : minIdx;
//         }
//         int temp = p.at(i);
//         p.at(i) = p.at(minIdx);
//         p.at(minIdx) = temp;
//     }
// }

// void quickSort(vector<int>& p, int left, int right) {
//     if (left < right) {
//         int pivot = p.at((left + right) / 2);
//         int checkLeft = left;
//         int checkRight = right;
//         int temp;

//         do {
//             while (p.at(checkLeft) < pivot) { checkLeft++; }
//             while (p.at(checkRight) > pivot) { checkRight--; }
//             if (checkLeft <= checkRight) {
//                 temp = p.at(checkLeft);
//                 p.at(checkLeft) = p.at(checkRight);
//                 p.at(checkRight) = temp;
//                 checkLeft++;
//                 checkRight--;
//             }
//         } while (checkLeft <= checkRight);
//         quickSort(p, left, checkRight);
//         quickSort(p, checkLeft, right);
//     }
// }

// void merge(vector<int>& p, int left, int mid, int right) {
//     int i = left, j = mid + 1, k = left;
//     vector<int> temp(p.size());
    
//     while (i <= mid && j <= right) {
//         if (p.at(i) < p.at(j)) { temp.at(k++) = p.at(i++); }
//         else { temp.at(k++) = p.at(j++); }
//     }
//     while (i <= mid) { temp.at(k++) = p.at(i++); }
//     while (j <= right) { temp.at(k++) = p.at(j++); }
//     for (i = left; i <= right; i++) { p.at(i) = temp.at(i); }
// }

// void mergeSort(vector<int>& p, int left, int right) {
//     if (left < right ) {
//         int mid = (left + right) / 2;       // O(1)   -> divide
//         mergeSort(p, left, mid);            // O(n/2) -> conquor
//         mergeSort(p, mid + 1, right);       // O(n/2) -> conquor
//         merge(p, left, mid, right);         // O(n-1) -> combine
//     }
// }

vector<int> countingSort(vector<int>& A) {
    vector<int> B(A.size());
    vector<int> C;
    int size_C = *max_element(A.begin(), A.end()) - *min_element(A.begin(), A.end()) + 1; // counting 배열의 크기

    C.resize(size_C);   // 기억상 count(C) 배열을 초기화 하는 과정 = O(k)

    for (int i = 0; i < A.size(); i++) { C.at(A.at(i) - *min_element(A.begin(), A.end()))++; } // A의 원소 값 만큼 C의 idx 값 증가 = O(n)

    for (int i = 1; i < C.size(); i++) { C.at(i) += C.at(i - 1); } // 누적합 계산 (원리는 모르겠으나 해야된다.) = O(k-1)

    for (int i = A.size() - 1; i >= 0; i--) { // 출력 배열 B에 A의 원소를 거꾸로 기입 = O(n)
        B.at(C.at(A.at(i) - *min_element(A.begin(), A.end())) - 1) = A.at(i);
        C.at(A.at(i) - *min_element(A.begin(), A.end()))--;
    }
    // 총 시간 복잡도 = k + (k - 1) + n + n = 2k + 2n - 1 = O(n + k)

    return B;
}

int main() {

    int size;
    srand(time(nullptr));

    cout << "enter the size of vector : ";
    cin >> size;

    vector<int> arr(size);

    for (int i = 0; i < size; i++) {
        arr.at(i) = rand() % 30 + 1;
    }

    // bubbleSort(arr);
    // insertionSort(arr);
    // selectionSort(arr);
    // quickSort(arr, 0, arr.size() - 1);
    // mergeSort(arr, 0, arr.size() - 1);
    arr = countingSort(arr);

    for (int data : arr) { cout << data << " "; }
    cout << endl;

    return 0;
}