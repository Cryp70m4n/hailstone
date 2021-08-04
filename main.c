#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>


#define print_failure(fmt, args...) fprintf(stderr, "\033[01;31m[X] Failure:\033[0m "fmt, ##args); fflush(stderr);
#define print_success(fmt, args...) fprintf(stdout, "\033[01;32m[+] Success:\033[0m "fmt, ##args); fflush(stdout);



#define TRUE 1
#define FALSE 0


typedef struct _argument {
	unsigned long long number;
	unsigned long long s;
	bool sc;
	bool n;
	bool r;
	bool check;
} argument;


bool IsArgument(const char * arg1, const char * arg2) {
	return (strcmp(arg1,arg2)?0:1);
}

unsigned long long counter = 0;

argument num;


int recurse(unsigned long long numb) {
	if(numb == 1) {
		printf("[!] Loop dected\n");
		exit(0);
	}

	if(numb % 2 == 0) {
		numb=numb / 2;
		printf("[N]-Number:%llu|[C]-Counter:%llu\n", numb, counter);
		counter++;
		sleep(num.s);
	}

	else if(numb % 2 == 1) {
		numb=numb * 3+1;
		printf("[N]-Number:%llu|[C]-Counter:%llu\n", numb, counter);
		counter++;
		sleep(num.s);
	}

	return recurse(numb);
}




int main(int argc, char ** argv){
	for (int i=0; i < argc; i++) {
		if (IsArgument(argv[i], "-n")) {
			if(i >= argc - 1) {
				print_failure("-n requires an value\n");
				return -1;
			}
			else {
				sscanf(argv[i+1], "%llu", &num.number);
				num.n = TRUE;
			}

			if (IsArgument(argv[i], "-r")) {
				if(i >= argc - 1) {
					num.r = TRUE;
					num.number = rand();
			}
				else {
					print_failure("-r doesn't require a value\n");
					return -1;
				}
			}


			if(IsArgument(argv[i], "-s")) {
				if(i >= argc - 1) {
					print_failure("-s requires an value sleep flag is now set to 1\n");
					sscanf("1", "%llu", &num.s);
				}
				else {
					sscanf(argv[i+1], "%llu", &num.s);
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
	
	if(num.n == FALSE && num.r == FALSE) {
		print_failure("Missing argument\n");
	}

	if(num.r == TRUE && num.n == TRUE) {
		print_failure("Can't use random and number argument at the same time\n");
		return -1;
	}



		else {
			if(num.s == 0) {
				num.s = 1;
			}
			recurse(num.number);
		}
	}
	return 0;
}
