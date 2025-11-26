#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

void merge(vector<int>& p, int left, int mid, int right) {
	int i = left, j = mid + 1, k = left;
	vector<int> temp(p.size());

	while (i <= mid && j <= right) {
		if (p.at(i) < p.at(j)) { temp.at(k++) = p.at(i++); }
		else { temp.at(k++) = p.at(j++); }
	}
	while (i <= mid) { temp.at(k++) = p.at(i++); }
	while (j <= right) { temp.at(k++) = p.at(j++); }
	for (i = left; i <= right; i++) { p.at(i) = temp.at(i); }
}

void mergeSort(vector<int>& p, int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;	// 상수 시간 1
		mergeSort(p, left, mid);		// T(p.size() / 2)
		mergeSort(p, mid+1, right);		// T(p.size() / 2)
		merge(p, left, mid, right);		// 최악의 경우 (n - 1)번 반복
	}
	// 총 시간 복잡도 T(n) = 2T(n/2) + (n - 1) + 1 = O(n log n)
}

int main() {

	vector<int> arr;
	int size;

	cout << "enter the size of vector : ";
	cin >> size;

	arr.resize(size);

	for (int i = 0; i < size; i++) { arr.at(i) = rand() % 30 + 1; }

	mergeSort(arr, 0, arr.capacity() - 1);

	for (int data : arr) { cout << data << " "; } 
	cout << endl;

	return 0;
}