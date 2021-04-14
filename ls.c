#include "apue.h"
#include <dirent.h>

int main(int argc, char* argv[]) {
  DIR *dp;
  struct dirent *dirp;
  if (argc != 2) err_quit("usage: ls <dir>");
  if ((dp = opendir(argv[1])) == NULL)
    err_sys("can't open %s", argv[1]);
  // now dir items are stored in dp.
  while ((dirp = readdir(dp)) != NULL)
    printf("%s\n", dirp->d_name);
  closedir(dp);
  return 0;
}
