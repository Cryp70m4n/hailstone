#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include<errno.h>


#define print_failure(fmt, args...) fprintf(stderr, "\033[01;31mFailure:\033[0m "fmt, ##args); fflush(stderr);
#define print_success(fmt, args...) fprintf(stdout, "\033[01;32mSuccess:\033[0m "fmt, ##args); fflush(stdout);

#define TRUE 1
#define FALSE 0


typedef struct _argument {
	unsigned long long number;
	bool random;
	bool n;
	bool r;
	bool check;
} argument;


bool IsArgument(const char * arg1, const char * arg2) {
	return (strcmp(arg1,arg2)?0:1);
}


argument num;

int main(int argc, char ** argv){
	for (int i=0; i < argc; i++) {
		if (IsArgument(argv[i], "-n")) {
			if(i >= argc - 1) {
				print_failure("-n requires an value\n");
				return -1;
			}
			else {
				sscanf(argv[i+1], "%d", &num.number);
				num.n = TRUE;
			}
		}
		
			if (IsArgument(argv[i], "-r")) {
				if(i >= argc - 1) {
					num.random = TRUE;
					num.r = TRUE;
					num.number = rand();
			}
				else {
					print_failure("-r doesn't require a value\n");
				}
			}
	}


	if(num.n == TRUE || num.r == TRUE) {
		num.check = TRUE;
	}

	if(num.number == 0 && num.check == TRUE) {
		print_failure("Number is zero\n");
		return -1;
	}
	else {
		if(num.r == TRUE && num.n == TRUE) {
			print_failure("Can't use both arguments at the same time\n");
			return -1;
		}

		else {
			if(num.r == TRUE) {
				print_success("Your random number is:%d\n", num.number);
			}
			if(num.n == TRUE) {
				print_success("Your number:%d\n", num.number);
				return 0;
			}
		}
	}
}
