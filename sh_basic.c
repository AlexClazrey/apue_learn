#include "apue.h"
#include <sys/wait.h> // for waitpid(pid_t, int, int)

int main() {
  char buf[MAXLINE];
  pid_t pid; // pid for sub-process
  int status; // process return code

  printf("%% ");
  // fgets returns NULL if receives EOF as first char.
  // by this you can press Ctrl-D to exit this program.
  while (fgets(buf, MAXLINE, stdin) != NULL) {
    if (buf[strlen(buf) - 1] == '\n')
      buf[strlen(buf) - 1] = 0;
    if ((pid = fork()) < 0) {
      err_sys("fork error");
    } else if (pid == 0) {
      // in child process
      execlp(buf, buf, (char*)0); // this should not return.
      err_ret("couldn't execute: %s", buf);
      exit(127);
    }
    // in parent process
    if ((pid = waitpid(pid, &status, 0)) < 0)
      err_sys("waitpid error");
    printf("%% ");
  }
  return 0;
}

