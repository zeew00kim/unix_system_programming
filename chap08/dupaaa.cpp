#include "header.hpp"

int main() {

    const char *fname = "test02.txt";
    int fd01, fd02, cnt;
    char buf[30];

    fd01 = open(fname, O_RDONLY); // 파일을 읽기 전용을 열기
    if (fd01 < 0) { 
        perror("file open"); // -1이면 열기 실패
        exit(-1); 
    } 

    fd02 = dup(fd01); // 예전 fd를 복사해 fd01 값을 fd02에 반환
    cnt = read(fd01, buf, 12); // cnt는 fd01에서 12byte 만큼 읽은 문자수
    buf[cnt] = '\0'; // cnt 번째 idx 값을 널로 초기화
    cout << "fd01 print (on the screen) : "  << buf << endl;

    lseek(fd01, 1, SEEK_CUR); // 현재 offset 위치에서 1Byte 이동
    cnt = read(fd02, buf, 12);
    buf[cnt] = '\0';
    cout << "fd02 print (on the test02.txt file) : "  << buf << endl;

    return 0;
}