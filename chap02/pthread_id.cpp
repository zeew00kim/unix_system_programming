#include <iostream>
#include <pthread.h>
#define NUM 5
using namespace std;

// pthread_self() 함수를 사용해 얻은 tid와 
// 매개변수로 받아온 *(pthread_t*)arg의 tid가 같다면 출력
void* print_func(void* arg) {
    pthread_t tid = pthread_self();
    if (*(pthread_t*)arg == tid) {
        cout << "this visitor thread id -> " << tid << endl;
    }
    pthread_exit(nullptr);
}

int main() {

    pthread_t arr[NUM];
    int ret_code;
    for (int i = 0; i < NUM; i++) {
        ret_code = pthread_create(&arr[i], nullptr, 
        print_func, &arr[i]);
        if (ret_code) {
            // 리턴 값이 0이면 스레드 생성 실패
            cout << "return code error -> " << ret_code << endl;
            exit(-1);
        }
    }
    pthread_exit(nullptr);

    return 0;
}