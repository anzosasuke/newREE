#include <stdio.h>

int main () {
	char array1[] = "12345";
char array2[] = "67890";

gets(array1);
printf("%s\n",array2 );
   char str[50];

   printf("Enter a string : ");
   gets(str);

   printf("You entered: %s", str);

   return(0);
}