#include <iostream>
#include <string> 
#include <cstring>
#include <stirng_view> // 별도 헤더 선언 필요
using namespace std;

int main() {
	
	string temp = "this is temp str";
	string_view sv = temp; // 복사 대입이 아닌 얕은 참조(view)
	temp.replace(0, 7, "I am a"); // 원본 변경 시 string_view도 변경
	cout << sv << endl; // 변경된 문자열로 출력
	
	const char* name = "zeew00"; // 문자열 상수 리터럴도 가능
	sv = name;
	cout << name << endl;
	
	char* major = new char[30];
	major = "computer engineering"; // 리터럴 값도 가능
	sv = major;
	cout << sv << endl;
	delete[] major;
	cout << sv << endl; // 원본 값의 메모리 반환으로 인한 쓰레기 값
	// 반드시 원본 값의 생명주기 범위 이내에서만 사용해야 함

	return 0;
}