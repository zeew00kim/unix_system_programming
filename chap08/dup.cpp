#include <iostream>
#include <fcntl.h>
#include <unistd.h>
using namespace std;

int main() {

    const char *fname = "dup.txt";
    int fd;

    if ((fd = creat(fname, 0666)) < 0) {
        perror("creat() func"); // -1 나오면 생성 실패
        exit(-1);
    }

    cout << "First print is on the screen" << endl;
    dup2(fd, 1);
    cout << "Second print is in this file" << endl;
    
    return 0;
}