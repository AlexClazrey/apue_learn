#include "apue.h"

int main() {
  // getpid() returns pid_t, guaranteed in the range of long integer by UNIX.
  printf("from process id %ld\n", (long)getpid());
  exit(0);
}
