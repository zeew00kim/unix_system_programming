#include <iostream>
#include <pthread.h>
using namespace std;

void *print_func(void* arg) {
    cout << "No." << *(static_cast<int*>(arg)) 
    << " thread is visit here now!!" << endl;
    pthread_exit(nullptr);
    return nullptr;
}

int main() {

    int size, ret_code;
    cout << "enter the size of arr : ";
    cin >> size;

    pthread_t *arr = new pthread_t[size];

    for (int i = 0; i < size; i++) {
        cout << "create No." << i << " thread" << endl;
        ret_code = pthread_create(&arr[i], nullptr, 
        print_func, &i);
        if (ret_code) {
            cout << "fatal error occured" << endl;
            exit(-1);
        }
    }

    pthread_exit(nullptr);

    delete[] arr;

    return 0;
}