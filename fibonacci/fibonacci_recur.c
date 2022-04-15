#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n){
	if(n == 1 || n == 2) return 1;
	return fibonacci(n-1) + fibonacci(n-2);
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

	printf("Result: %i\n", fibonacci(n));

	return 0;
}
