#include <stdio.h>

int local_auto;
int* init(void) {

  local_auto = 24;
  printf("%p", &local_auto);
  /* Initialize array */
  return &local_auto;

    
}

int main(void)
{
  int *p;
p = init();

printf("%ls", p);
}