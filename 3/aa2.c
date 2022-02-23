#include <stdio.h>


char *init_array(void) {
  char array[10];
  /* Initialize array */
  for ( int i = 0; i < 10; i++ ) {
      array[i] = i + 100;
    }
  return array;

}

int init_array1(void) {
  int i = 25;
    
  return i;
  
}


int main(void)
{
  char *p; int a;
p = init_array();
a = init_array1();
printf("%d", a);
printf("%s\n", p);

}

//warning: function returns address of local variable [-Wreturn-local-addr]

//In this noncompliant code sample, the function init_array() returns a pointer to a character array with automatic storage duration, which is accessible to the caller: