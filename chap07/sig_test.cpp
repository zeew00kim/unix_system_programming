#include <iostream>
#include <unistd.h>
#include <signal.h>
using namespace std;

void timeout(int signo) { // 매개변수로 SIGALRM(14) 정수 값을 받음
	printf("Timeout (5 sec), Abort\n");
	exit(1);
}

int main() {

	int n;
	char buf[80];
	
	// 5초가 지나면 커널이 SIGALRM 시그널 전송 (catch 방식)
	signal(SIGALRM, timeout); // SIGALRM -> signal.h 에 정의된 매크로 상수
	
	while (1) {
		printf("Enter input (timeout 5 sec)\n");
		alarm(5); // 5초 후에 SIGALRM 시그널을 프로세스 자신에게 보내도록 요청
		if ((n = read(STDIN_FILENO, buf, 80)) > 0) { alarm(0); }
		// 5초 동안 사용자의 입력을 대기
		// 정해진 5초 이내에 사용자가 입력 시 buf에 값을 저장
		// 5초를 넘길 시 timeout 함수를 호출시켜 exit(1);
	}
    
	return 0;
}