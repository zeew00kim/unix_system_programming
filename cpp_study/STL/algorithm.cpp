#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

int main() {

    int size;
    vector<int> arr;
    vector<int>::iterator it;
    srand(time(nullptr));

    cout << "enter the size of vector -> ";
    cin >> size;
    arr.resize(size);

    for (int i = 0; i < arr.size(); i++) {
        arr.at(i) = rand() % 20 + 1;
    }

    // sort() 함수는 기본적으로 오름차순 정렬
    sort(arr.begin(), arr.end(), less<int>());
    // 내림차순 시 functional 헤더 선언 필요
    sort(arr.begin(), arr.end(), greater<int>());

    for (int data : arr) { cout << data << " "; }
    cout << endl;

    // 벡터에서 최소값을 찾아 반환
    it = min_element(arr.begin(), arr.end());
    cout << "find min value -> " << *it << endl;
    
    // 벡터에서 최댓값을 찾아 반환
    it = max_element(arr.begin(), arr.end());
    cout << "find max value -> " << *it << endl;

    return 0;
}