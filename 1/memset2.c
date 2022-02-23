#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// memset() is used to fill a block of memory with a particular value.
//memset is defined in string.h

// The compiler is generally allowed to remove code
// that does not have any effect, according to the abstract machine of the C language.
// This means that if you have a buffer that contains sensitive data (for instance passwords),
// calling memset on the buffer before releasing the memory will probably be optimized away.


// size_t is an unsigned integral data type which is defined in various header files such as:
 // <stddef.h>, <stdio.h>, <stdlib.h>, <string.h>, < time .h>, <wchar.h>
 // It's a type which is used to represent the
// size of objects in bytes and is therefore used as the return type by the sizeof operator.

void f(char *password, size_t bufferSize, char *token1, size_t buffersz)
{

  char localToken[256];
  char localBuffer[256];
  // init(localToken, password);
  memset(password, ' ', strlen(password));
  password = token1; // Noncompliant, password is about to be freed
  memset(token1, ' ', strlen(token1));
  
  memset(localToken, ' ', strlen(localBuffer)); // Noncompliant, localToken is about to go out of scope
  free(password);
  free(token1);
}
// ptr ==> Starting address of memory to be filled
// x   ==> Value to be filled
// n   ==> Number of bytes to be filled starting
//         from ptr to be filled
// void *memset(void *ptr, int x, size_t n);

int main()
{
char *password;
char *token1;
token1 = (char*)malloc(10);
password = (char*)malloc(10);//typecasting 
printf("enter your password: ");

scanf("%s", password);
printf("%s", password);

f(password, 10, token1, 10);
printf("%s\n",password );
return 0;
}


// The code in the example will behave correctly if it is executed verbatim, but if the code is compiled using an optimizing compiler, 
// such as Microsoft Visual C++ .NET or GCC 3.x, then the call to memset() will be removed as a dead store because the buffer pwd is not 
// used after its value is overwritten [18]. Because the buffer pwd contains a sensitive value, the application may be vulnerable to attack
//  if the data are left memory resident. If attackers are able to access the correct region of memory, they may use the recovered password 
//   to gain control of the system.

// It is common practice to overwrite sensitive data manipulated in memory, such as passwords or cryptographic keys, in order to prevent 
// attackers from learning system secrets. However, with the advent of optimizing compilers, programs do not always behave as their source code 
// alone would suggest. In the example, the compiler interprets the call to memset() as dead code because the memory being written to is not 
// subsequently used, despite the fact that there is clearly a security motivation for the operation to occur. The problem here is that many
//  compilers, and in fact many programming languages, do not take this and other security concerns into consideration in their efforts to improve
//  efficiency.

// Attackers typically exploit this type of vulnerability by using a core dump or runtime mechanism to access the memory used by a particular 
// application and recover the secret information. Once an attacker has access to the secret information, it is relatively straightforward to
//  further exploit the system and possibly compromise other resources with which the application interacts.

  