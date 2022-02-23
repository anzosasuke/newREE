#include <stdlib.h>
#include<stdio.h>

int main(){





void *ptr =NULL;

//do some work, which might goto error
posix_memalign(&ptr, 6000000000000000000, 1000000*60000000000000);

// if(ptr)
// {
//   for(int n=0;n<50;n++)
//     {
//       (int *)ptr[n] = n*n;
//     }
//   for(int n=0; n<4; ++n) // print it back out
//   printf("ptr[%d] == %d\n", n, ptr[n]);
//     }

//do some more work, which might goto error
free(ptr);
    //more cleanup;


}
