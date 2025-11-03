#include <iostream>
#include <unistd.h>
#include <sys/types.h>
using namespace std;

int main() {

    pid_t pid;

    cout << "PID (current) : \t" << getpid() << endl;
    cout << "PPId (Parent) : \t" << getppid() << endl;
    cout << "Real UID : \t\t" << getuid() << endl;
    cout << "Effective UID : \t" << geteuid() << endl;
    cout << "Real GID : \t\t" << getgid() << endl;
    cout << "Effective GID : \t" << getegid << endl;

    return 0;
}