#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

auto merge(vector<int>& p, int left, int pivot, int right) -> void {
    int i = left, j = pivot + 1, k = left;
    vector<int> temp(p.size());
    while (i <= pivot && j <= right) {
        if (p.at(i) < p.at(j)) temp.at(k++) = p.at(i++);
        else temp.at(k++) = p.at(j++);
    }
    while (i <= pivot) temp.at(k++) = p.at(i++);
    while (j <= right) temp.at(k++) = p.at(j++);
    for (i = left; i <= right; i++) p.at(i) = temp.at(i);
}

auto mergeSort(vector<int>& p, int left, int right) -> void {
    if (left < right) {
        int pivot = (left + right) / 2;
        mergeSort(p, left, pivot);
        mergeSort(p, pivot + 1, right);
        merge(p, left, pivot, right);
    }
}

int main() {

    int size;
    vector<int> arr;
    srand(time(nullptr));

    cout << "enter the size of vector : ";
    cin >> size;

    arr.resize(size);

    for (int i = 0; i < size; i++) {
        arr.at(i) = rand() % 30 + 1;
    }

    mergeSort(arr, 0, size - 1);

    for (int data : arr) cout << data << " ";
    cout << endl;

    return 0;
}