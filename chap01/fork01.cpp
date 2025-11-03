#include <iostream>
#include <unistd.h>
#include <sys/types.h>
using namespace std;

int main() {

    pid_t pid;

    cout << "PID, before the fork() sys call -> " << getpid() << endl;

    if ((pid = fork()) == -1) {
        perror("fork sys call");
        exit(1);
    }
    else if (pid == 0) { // 자식 프로세스일 경우 pid = 0
        cout << "This is Child process PID -> " << getpid() << endl;
    }
    else {
        // 부모 프로세스일 경우 pid > 0
        cout << "This is Parent Process, PID -> " << getpid() << endl;
        // 부모 프로세스의 pid 변수에는 자식 프로세스의 PID가 저장
        cout << "and this process's child PID -> " << pid << endl;
    }

    int end_data = getpid(); // 부모, 자식에 따라 PID 값이 다름

    cout << "end of process -> " << end_data << endl;

    return 0;
}