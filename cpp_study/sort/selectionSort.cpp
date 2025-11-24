#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

auto selectionSort(vector<int>& p) {
    for (int i = 0; i < p.size() - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < p.size(); j++) {
            if (p.at(j) < p.at(minIdx)) { 
                minIdx = j; 
            }
        }
        int temp = p.at(minIdx);
        p.at(minIdx) = p.at(i);
        p.at(i) = temp;
    }
}

int main() {

    int size;
    vector<int> arr;
    srand(time(nullptr));

    cout << "enter the size of vector : ";
    cin >> size;

    arr.resize(size);

    for (int i = 0; i < arr.size(); i++) {
        arr.at(i) = rand() % 20 + 1;
    }

    selectionSort(arr);

    for (int data : arr) {
        cout << data << " ";
    }
    cout << endl;

    return 0;
}