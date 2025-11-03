#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
using namespace std;

int main() {

    pid_t pid;

    cout << "Before fork() system call (PID : " << pid << ")" << endl;

    if ((pid = fork()) == -1) {
        perror("result of fork sys call");
        exit(1);
    }
    else if (pid == 0) {
        cout << "this is child process (PID : " << getpid() << ")" << endl;
        sleep(2);
        cout << "end of child..." << endl;
    }
    else {
        cout << "Parent : " << getpid() << ", child : " << pid << endl;
        cout << "end of parent" << endl;
    }

    cout << "program off" << endl;

    return 0;
}