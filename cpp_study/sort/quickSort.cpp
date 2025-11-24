#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

auto quickSort(vector<int>& p, int left, int right) -> void {
    if (left < right) {
        int pivot = p.at((left + right) / 2);
        int checkLeft = left;
        int checkRight = right;
        int temp;

        do {
            while (p.at(checkLeft) < pivot) {
                checkLeft++;
            }
            while (p.at(checkRight) > pivot) {
                checkRight--;
            }
            if (checkLeft <= checkRightE) {
                temp = p.at(checkLeft);
                p.at(checkLeft) = p.at(checkRight);
                p.at(checkRight) = temp;
                checkLeft++;
                checkRight--;
            }
        } while (checkLeft <= checkRight);
        quickSort(p, left, checkRight);
        quickSort(p, checkLeft, right);   
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

    quickSort(arr, 0, size - 1);

    for (int data : arr) cout << data << " ";
    cout << endl;

    return 0;
}