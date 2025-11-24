#include "header.hpp"

int main() {

    const char *fname = "text.txt";
    int fd01, fd02, cnt;
    char buf[30];

    fd01 = open(fname, O_RDONLY);
    if (fd01 < 0) {
        perror("open error");
        exit(-1);
    }
    fd02 = dup(fd01);
    cnt = read(fd01, buf, 12);
    buf[cnt] = '\0';
    cout << "fd01's print : " << buf << endl;

    lseek(fd01, 1, SEEK_CUR);

    cnt = read(fd02, buf, 12);
    buf[cnt] = '\0';
    cout << "fd02's print : " << buf << endl;

    return 0;
}