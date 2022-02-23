#include <stdio.h> 
#include <string.h> 
int main() 
{ 
    char src[] = "Iamstring"; 
    char dest[10];
  // Here destination is not large 
    // enough to store the src. so the 
    // behaviour of strcpy is unspecified. 
    // program may crashed, but its 
    // printing Iamstring
  
    // copying src into dest. The strcpy() function does not specify the size of the destination array, so buffer overrun is often a risk.
    strcpy(dest, src); 
    printf("Copied string: %s\n", dest); 
      
    return 0; 
} 