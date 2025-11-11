#include <iostream>
#include <signal.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/sem.h>
using namespace std;

#define SHMKEY01 static_cast<key_t>(0x7000);
#define SHMKEY02 static_cast<key_t>(0x7001);
#define SHMKEY static_cast<key_t>(0x7000);

int main() {



    return 0;
}