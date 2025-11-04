#include <pthread.h>
#include <unistd.h>
#include <iostream>
using namespace std;

int sum = 1;

void* add_func(void* arg) {
    sum += *(static_cast<int*>(arg));
    pthread_exit(nullptr);
}

int main() {

    int ret_code;
    pthread_t arr[5];
    
    for (int i = 0; i < 5; i++) {
        ret_code = pthread_create(&arr[i], nullptr, 
        add_func, &i);
        if (ret_code) {
            cout << "thread creation work failed" << endl;
            exit(-1);
        }
    }

    cout << "result of sumation -> " << sum << endl;
    pthread_exit(nullptr);

    return 0;
}