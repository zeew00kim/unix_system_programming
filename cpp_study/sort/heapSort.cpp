#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#define V_SIZE 10
using namespace std;

void heapify(vector<int>& v, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && v.at(left) > v.at(largest)) {
        largest = left;
    }
    if (right < n && v.at(right) > v.at(largest)) {
        largest = right;
    }
    if (largest != i) {
        int temp = v.at(i);
        v.at(i) = v.at(largest);
        v.at(largest) = temp;
        heapify(v, n, largest);
    }
}

void heapSort(vector<int>& v, int n) {
    for (int i = n / 2 -1; i >= 0; i--) {
        heapify(v, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        int temp = v.at(0);
        v.at(0) = v.at(i);
        v.at(i) = temp;
        heapify(v, i, 0);
    }
}

int main() {

    srand(time(nullptr));
    vector<int> arr;
    arr.resize(V_SIZE);
    int n = arr.size();

    for (int i = 0; i < arr.size(); i++) {
        arr.at(i) = rand() % 10 + 1;
    }

    heapSort(arr, n);
    
    for (int data : arr) {
        cout << data << " ";
    }
    cout << endl;

    return 0;
}