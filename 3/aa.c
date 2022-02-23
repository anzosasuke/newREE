
#include <stdio.h>
  
const char *p;
 int abc = 1400;
void dont_do_this(void) {

  const char c_str[] = "This will change";
  p = c_str; /* Dangerous */
}
 
void innocuous(void) {
  int bb = 40;
  printf("abc+bb:%d", abc+bb);
  abc = abc + bb;
  printf("%s\n", p);
}
 
int main(void) {
  // int abc = 1400;

  dont_do_this();
  innocuous();
  return 0;
}