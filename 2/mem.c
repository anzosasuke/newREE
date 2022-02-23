#include<string.h>
#include<stdio.h>
#include <stdbool.h> 
#include<stdlib.h>
// #define __STDC_WANT_LIB_EXT1__ 1
// using std::string;

// #include <memory>

// The specifics of this function are
// not important for demonstrating this bug.
const char* getPasswordFromUser(){
	char passwd[20];
	printf("Enter password:\n");
	scanf("%s", passwd);
	return passwd;
}

bool isPasswordCorrect() {
	bool isPasswordCorrect = false;
	char Password[]="password";

	if(Password == getPasswordFromUser()) {
		isPasswordCorrect = true;
	}

	// This line is removed from the optimized code
	// even though it secures the code by wiping
	// the password from memory.
	// #ifdef __STDC_LIB_EXT1__
	memset(Password, 0 , sizeof(Password));
	// int r = memset_s(Password, sizeof(Password), 0, sizeof(Password));
	// #endif

	return isPasswordCorrect;
}

void main(){
if(isPasswordCorrect()){
	printf("true");

}


}
//use memset_s
// End of Example Code

//It's considered good practice to remove sensitive data from memory when it's no long needed 
// so that the sensitive data doesn't accidentally end up in the swap file, temp file, memory dump file, etc.

//However, in the above example, the optimizing compiler removes the "memset" function as part of "dead store removal" optimization. 
 // The optimizing compiler realizes that "memset" writes to "Password" but "Password" is never again read; 
// hence, it is removed as part of the "dead store removal" optimization.
// The compiler is generally allowed to remove code that does not have any effect, according to the abstract machine of the C language. 
// This means that if you have a buffer that contains sensitive data (for instance passwords),
//  calling memset on the buffer before releasing the memory will probably be optimized away.