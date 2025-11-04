#include <iostream>
#include <pthread.h>
using namespace std;

int sum = 1;
// 공유 메모리 Data 영역에 있는 sum을 보호하기 위한 뮤텍스 락
pthread_mutex_t sum_lock; 

void *sum_func(void* arg) {
    pthread_mutex_lock(&sum_lock);
    sum += *(static_cast<int*>(arg));
    pthread_mutex_unlock(&sum_lock);
    pthread_exit(nullptr);
}

int main() {

    int size, ret_code;
    
    cout << "enter the size of array : ";
    cin >> size;

    pthread_t *arr = new pthread_t[size];

    for (int i = 0; i < size; i++) {
        ret_code = pthread_create(&arr[i], 
        nullptr, sum_func, &i);
        if (ret_code) {
            cout << "thread creation failed" << endl;
            exit(-1);
        }
    }

    for (int i = 0; i < size; i++) {
        // 모든 스레드의 종료를 대기
        pthread_join(arr[i], nullptr);
    }
    
    // 임계구역을 통해 안전하게 수행된 연산 결과 출력
    cout << "result of summation -> " << sum << endl;

    // 사용이 종료된 뮤텍스 자원 정리
    pthread_mutex_destroy(&sum_lock);
    pthread_exit(nullptr);

    return 0;
}