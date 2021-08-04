#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


#define unsigned long long number;



bool IsArgument(const char * arg1, const char * arg2) {
	return (strcmp(arg1,arg2)?0:1);
}

int main(int argc, char ** argv){
	for (int i=0; i < argc; i++) {
		if(i >= argc - 1) {
			printf("-n requires an value\n");
		}
		else {
			strncpy(number, argv[i+1], sizeof(number));
		}
	}
	return 0;
}
