#include <iostream>
#include <string>
#include <vector>
using namespace std;

// SRP(단일책임원칙) -> 모든 클래스는 하나의 객체만을 가짐

// User 클래스에서의 기능은 오직 사용자 정보를 보관하는 것
// 이 클래스를 수정할 때엔 사용자의 이름, 학번을 수정할 때에만 수정
// 올바른 예) 사용자 id -> 사용자 age 이런 경우에 수정이 가능
// 잘못된 예) 사용자 출력 방식이 바뀔 때 수정? -> SRP 위반!!
class User {
    string name;
    int id;
public:
    User(const string& name, int id) : name{name}, id{id} {}
    auto get_name() -> string const { return name; }
    auto get_id() -> int const { return id; }
};

// 사용자 정보를 벡터에 저장 및 조회하는 기능만 담당
// 잘못된 예) 이름 유효성 검사 기능 추가? -> SRP 위반
class UserRepo {
    vector<User> user;
public:
    auto save(const User& u) { user.emplace_back(u); }
    const vector<User>& find_all() const { return user; }
};

// 비즈니스 로직(사용자를 벡터에 등록하는 핵심)만 담당
// 사용자 정보 등록 정책이 바뀐 경우(이름 중복 검사 등)에 수정 가능
class UserService {
    UserRepo& repo;
public:
    UserService(const UserRepo& repo) : repo{repo} {}
    auto registerUser(const string& name, int id) -> void {
        repo.save(User(name, id)); // R-value 인자 전달
    }
};

// 벡터에 등록된 내용을 출력하는 기능만 담당
// 출력 format 변경 시 이 부분을 수정
class UserPrinter {
public:
    auto print(const vector<int>& user) {
        for (auto &data : user) {
            cout << "this user name : " << data.name;
            cout << ", id : " << data.id << endl;
        }
    }
};

int main() {

    UserRepo repo;              // 사용자 정보를 User에 저장/조회
    UserService service(repo);  // 시용지 정보를 UserRepo에 추가
    UserPrinter printer;        // 사용자 정보 출력

    service.registerUser("zeew00", 2022158067);
    service.registerUser("zaewan", 2022158066);

    printer.print(repo.findAll()); // 등록된 모든 사용자 정보를 출력

    return 0;
}