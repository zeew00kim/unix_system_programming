#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
using namespace std;

int main() {

    pid_t pid;
    int status, exit_status;

    if ((pid = fork()) == -1) { 
        perror("fork sys call");
        exit(1);
    }
    else if (pid == 0) {
        cout << "child process" << getpid();
        cout << " is sleeping now" << endl;
        sleep(0.1);
        exit(2);
    }

    int sec = 0;

    // waitpid() -> 특정 pid의 종료를 대기
    // &status -> 함수 종료를 저장할 주소
    // WNOHANG -> 자식이 실행 ? 0 : 1
    while (waitpid(pid, &status, WNOHANG) == 0) {
        cout << "I'm still waiting child" 
        << sec++ << "sec" << endl;
    }

    if (WIFEXITED(status)) { // 자식의 종료 상태 검사
        exit_status = WEXITSTATUS(status); // 자식의 종료 값
        cout << "exit status of child process -> "
        << exit_status << endl;
    }
    
    return 0;
}