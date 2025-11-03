#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
using namespace std;

int main() {

    int status, exit_status;
    pid_t pid01, pid02;

    pid01 = fork();

    if (pid01 == 0) {
        sleep(5);
        exit(5);
    }
    else {
        pid01 = wait(&status);
        cout << "child PID : " << pid01 << endl;
    }

    // what if exited -> 자식 프로세스의 정상 종료 확인
    if (WIFEXITED(status)) {
        // what exit status -> 종료된 exit() 값
        exit_status = WEXITSTATUS(status);
        cout << "status of child exit() : " << exit_status << endl;
    }

    return 0;
}