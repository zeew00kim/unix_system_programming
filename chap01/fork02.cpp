#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
using namespace std;

int glob = 11;
char buf[] = "write to STDOUT\n";

int main() {

    int local = 8;
    pid_t pid;

    // strlen() 함수는 널 값은 제외하고 문자열 길이를 구하기 때문에 +1
    // write() 함수도 시스템 콜의 일부이며, STDOUT은 그냥 화면 출력한다는 거
    if (write(STDOUT_FILENO, buf, strlen(buf) + 1) != sizeof(buf)) {
        perror("file descripting");
        exit(1);
    }
    
    cout << "[ before fork() sys call ]" << endl;

    if ((pid = fork()) < 0) {
        perror("fork sys call");
        exit(2);
    }
    else if (pid == 0) { glob++, local++; }
    else { sleep(3); }

    int data = (pid == getpid()) ? pid : getpid();

    cout << "End of process -> " << data << endl;

    return 0;
}