#include<stdio.h>

void squirrel_away(char **ptr_param) {
  char local[10];
  /* Initialize array */
    for ( int i = 0; i < 10; i++ ) {
      local[i] = i + 100;
  *ptr_param = local;
}}
 
void rodent(void) {
  char *ptr;
  squirrel_away(&ptr);
  printf("%s ", ptr);
  /* ptr is live but invalid here */
}

int main(void)
{
	rodent();

}


// In this noncompliant code example, the function squirrel_away() stores a pointer to local variable local into a location pointed to by function parameter ptr_param. Upon the return of squirrel_away(), the pointer ptr_param points to a variable that has an expired lifetime.