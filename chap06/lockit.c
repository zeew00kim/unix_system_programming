#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>

int main() {
    int fd;
    struct flock my_lock;

    my_lock.l_type = F_WRLCK;        // lock 유형 = 쓰기 락
    my_lock.l_whence = SEEK_SET;     // offset 위치 = 가장 첫 번째 위치
    my_lock.l_start = 0;            // offset 기준 락 시작 지점까지의 거리 = 0
    my_lock.l_len = 10;             // l_start 부터 락을 설정할 세그먼트의 byte 크기

    fd = open("locktest", O_RDWR | O_CREAT);   // 읽기/쓰기 권한으로 파일 열기

    // 첫 10byte 만큼 lock 설정
    if (fcntl(fd, F_SETLKW, &my_lock) == -1) {
        perror("Parent Locking"); // 다른 프로세스에 의해 블로킹 시 sleep
        exit(1);
    }

    printf("record has been locked (by Parent Process)\n");

    switch(fork()) {
    case -1:
        perror("fork");
        exit(1);
    case 0:
        my_lock.l_len = 5;
        if (fcntl(fd, F_SETLKW, &my_lock) == -1) {
            perror("Child : locking");
            exit(1);
        }
        printf("child : locked\n");
        printf("child : exiting\n");
    }

    sleep(5); // 부모 프로세스일 경우 5초간 대기

    printf("parent : exiting\n");

    exit(0);
}