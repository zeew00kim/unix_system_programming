#include <iostream>
#include <pthread.h>
using namespace std;

pthread_mutex_t lock;
int glob = 1;

void *task(void* arg) {
    pthread_mutex_lock(&lock);
    cout << "Thread ID " << pthread_self() << endl;
    glob *= 2;
    cout << "and this thread's data : " << glob << endl;
    pthread_mutex_unlock(&lock);
    pthread_exit(nullptr);
}

int main() {

    pthread_t t1, t2;
    int id01 = 1, id02 = 2, size, ret_code;

    cout << "enter the size of arr : ";
    cin >> size;

    pthread_t *arr = new pthread_t[size];

    pthread_mutex_init(&lock, nullptr);

    for (int i = 0; i < size; i++) {
        ret_code = pthread_create(&arr[i], nullptr, task, nullptr);
        if (ret_code) {
            cout << "ret_code is not 0" << endl;
            exit(-1);
        }
    }

    for (int i = 0; i < size; i++) {
        pthread_join(arr[i], nullptr);
    }

    pthread_mutex_destroy(&lock);

    delete[] arr;

    return 0;
}