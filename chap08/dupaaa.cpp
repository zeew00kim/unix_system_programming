#include "header.hpp"

int main() {
	
	const char *fname = "test02.txt";
	itn fd01, fd02, cnt; // FD 두 개와 읽은 바이트수를 저장할 cnt 변수
	char buf[30]; // 데이터를 읽어올 때 사용할 버퍼 (최대 30바이트)
	
	fd01 = open(fname, O_RDONLY); // 파일을 읽기 전용으로 열기
	if (fd01 < 0) {
		perror("file open"); // -1이면 열기 실패
		exit(-1);
	}
	
	// fd01과 fd02는 같은 파일을 가리키며 오프셋을 공유
	fd02 = dup(fd01); // 예전 FD를 복사해 fd01 값을 fd02에 반환
	
	// fd01에서 12바이트 만큼 읽은 문자수 저장
	cnt = read(fd01, buf, 12) // file offset은 12만큼 이동
	buf[cnt] = '\0'; // cnt 번째 idx 값을 널로 초기화 (문자열의 끝을 표시)
	cout << "fd01's print -> " << buf << endl; // fd01에서 읽은 12바이트 내용 출력
	
	lseek(fd01, 1, SEEK_CUR); // 현재 offset 위치(12)에서 + 1바이트 이동 -> 13바이트
	
	cnt = read(fd02, buf, 12); // fd02에서 현재 offset(13)부터 최대 12바이트 읽음
	buf[cnt] = '\0'; 
	cout << "fd02's print -> " << buf << endl; // fd02에서 읽은 12바이트 내용 출력

	return 0;
}