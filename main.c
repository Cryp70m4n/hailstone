/*
Made by:Cryp70m4n and AkisaRazbu
Version:1.0

USAGE:
./hailstone

*/


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
	bool n;
} argument;


bool IsArgument(const char * arg1, const char * arg2) {
	return (strcmp(arg1,arg2)?0:1);
}

unsigned long long counter = 0;

argument num;

void blue() {
  printf("\033[0;34m");
}

void reset() {
  printf("\033[0m");
}

int recurse(unsigned long long numb) {
	if(numb < 0) {
		print_failure("Number below zero\n");
		exit(0);
	}
	if(numb == 0) {
		print_failure("Zero dected\n");
		exit(0);
	}
	if(numb == 1) {
		print_failure("Loop dected\n");
		exit(0);
	}

	if(numb % 2 == 0) {
		numb=numb / 2;
		blue();
		printf("[N]-Number:%llu|[C]-Counter:%llu\n", numb, counter);
		reset();
		counter++;
		sleep(1);
	}

	else if(numb % 2 == 1) {
		numb=numb * 3+1;
		blue();
		printf("[N]-Number:%llu|[C]-Counter:%llu\n", numb, counter);
		reset();
		counter++;
		sleep(1);
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
		}
	}


	if(num.n == FALSE) {
		print_failure("Missing argument\n");
	}

	if(num.number == 0) {
		print_failure("Number is zero\n");
		return -1;
	}

	else {
		recurse(num.number);
	}


	return 0;
}
