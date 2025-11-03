#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
using namespace std;

int main() {

    pid_t pid01, pid02;
    int exit_status;

    pid01 = fork();

    if (pid01 == -1) {
        perror("fork sys call");
        exit(1);
    }
    else if (pid01 == 0) {
        // execv(vector) -> fork() 자식 프로세스를 새로운 기능으로 overwrite
        const char* argv[] = {"ls", "-al", nullptr};
        execv("/bin/ls", const_cast<char * const *>(argv));
        // exec() 시스템 콜 실패 시 아래의 로직이 실행됨
        // 성공했다면 이 코드 자체는 메모리에서 사라진다.
        cout << "if you see this string, exec sys call failed..." << endl;
        exit(2);
    }
    else {
        pid02 = wait(&exit_status);
        cout << "child process PID -> " << pid02 << endl;
        cout << "and child's exit_status -> " << exit_status;
        cout << endl;
    }

    return 0;
}