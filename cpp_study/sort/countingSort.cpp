#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 정렬 알고리즘 내부에서 정렬을 하는 모순이지만 편의를 위해 정렬
// k = max - min + 1 값을 구하기 위한 과정
int get_size(vector<int> p) {
    sort(p.begin(), p.end());
    return p.back() - p.front() + 1;
}

int main() {

    vector<int> A = { 2, 5, 3, 0, 2, 3, 0, 3 };
    vector<int> B;
    vector<int> C;

    int cnt = get_size(A);

    C.resize(cnt);

    for (int i = 0; i < A.size(); i++) {
        C.at(A.at(i))++; // ex) A.at(i) = 2, C.at(A.at(i)) = C.at(2), C.at(2)++;
        // 이 과정으 8번 반복하면 -> { 2, 0, 2, 3, 0, 1 } 과 같은 결과가 나옴
    }

    for (int i = 1; i < C.size(); i++) {
        C.at(i) += C.at(i - 1); // 이 과정 5번 반복 시 -> { 2, 2, 4, 7, 7, 8 }
    }

    B.resize(A.size());

    for (int i = A.size() - 1; i >= 0; i--) {
        if (C.at(A.at(i)) > 0) {
            B.at(C.at(A.at(i)) - 1) = A.at(i);
            C.at(A.at(i))--;
        }
    }

    for (int data : B) { cout << data << " "; }
    cout << endl;

    return 0;
}