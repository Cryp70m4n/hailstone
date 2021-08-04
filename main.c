#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>




typedef struct _argument {
	unsigned long long number;
} argument;


bool IsArgument(const char * arg1, const char * arg2) {
	return (strcmp(arg1,arg2)?0:1);
}


argument num;

int main(int argc, char ** argv){
	for (int i=0; i < argc; i++) {
		if (IsArgument(argv[i], "-n")) {
			if(i >= argc - 1) {
				printf("-n requires an value\n");
				return -1;
			}
			else {
				sscanf(argv[i+1], "%d", &num.number);
			}
		}
	}
	printf("Your number:%d\n", num.number);
	return 0;
}
