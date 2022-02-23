#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{

char array[16] = {'z','l','a', 'b', 'c', 'd', 's', 'h', 'p', 't'};

void *pos = memchr(array, '@', 142);
printf("String after @ is |%p|",pos);
 // Noncompliant, buffer overflow that could expose sensitive data
return(0);
}