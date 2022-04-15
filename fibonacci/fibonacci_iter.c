#include <stdio.h>
#include <stdlib.h>

long fibonacci(int n){
	long n1 = 1, n2 = 1, res;
	int i;

	if(n == 1 || n == 2) return 1;	

	for(i = 0; i < n-2; i++){
		res = n1 + n2;
		n2 = n1;
		n1 = res;
	}

	return res;
}

int main(int argc, char** argv){
  int n;

	if(argc != 2){
		printf("Usage: \"./program n\" (n = fibonacci_pos)\n");
		return 1;
	}

	n = atoi(argv[1]);

	if(n == 0){
		printf("The n should be greater than 0");
		return 1;
	}

	printf("Result: %li\n", fibonacci(n));

	return 0;
}
