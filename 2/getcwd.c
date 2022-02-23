#include <unistd.h>
#undef _POSIX_SOURCE
#include <stdio.h>

int main() {
  char cwd[256];

  if (chdir("/tmp") != 0)
    perror("chdir() error()");
  else {
    if (getcwd(cwd, 5000000) == NULL)
      perror("getcwd() error");
    else
      printf("current working directory is: %s\n", cwd);
  
return 0;
  }
}