#include "apue.h"

int main(void) {
  char c;
  // getc(FILE*) and getchar() is standard io func.
  // getch() and getche() [getch with echo] are ms-dos funcs, reading key with no buffer.
  // getchar() equals to getc(stdin).
  while ((c = getc(stdin)) != EOF) {
    if (putc(c, stdout) == EOF) break;
  }
  if (ferror(stdin)) err_sys("input error");
  return 0;
}
