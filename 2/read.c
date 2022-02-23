#include <fcntl.h> 
#include <stdio.h> 
#include <string.h>
#include <unistd.h> 
// #include <iostream>


int main(){


char buf[64], in[MAX_SIZE];
printf("Enter buffer contents:\n");
read(0, in, MAX_SIZE-1);
printf("Bytes to copy:\n");
scanf("%d", &bytes);
memcpy(buf, in, bytes);

}


// where a program reads data and then trusts a value from the data in subsequent memory operations on the remaining data