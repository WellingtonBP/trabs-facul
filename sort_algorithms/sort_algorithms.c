#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void bubble_sort(int *arr, int n){
	int swap = 1, i = 0, end = 1, aux = 0, flag = 0;

	flag++;
	while(swap){
		swap = 0;
		flag += 2;
		for(i = 0; i < n - end; i++){
			flag++;
			if(arr[i] > arr[i+1]){
				aux = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = aux;
				swap = 1;
				flag += 4;
			}
		}
		end++;
		flag++;
	}
	printf("\nBubble flag: %i\n", flag);
}

void selection_sort(int *arr, int n){
	int i = 0, j = 0, aux = 0, lower_pos = 0, flag = 0;

	flag++;
	for(i = 0; i < n-1; i++){
		flag += 2;
		lower_pos = i;
		for(j = i+1; j < n; j++){
			flag++;
			if(arr[j] < arr[lower_pos]){
				flag++;
				lower_pos = j;
			}
		}
		flag++;
		if(lower_pos != i){
			aux = arr[lower_pos];
			arr[lower_pos] = arr[i];
			arr[i] = aux;
			flag += 3;
		}
	}
	printf("\n selection flag: %i\n", flag);
}

void insertion_sort(int *arr, int n){
	int i = 0, j = 0, current = 0, flag = 0;

	flag++;
	for(i = 1; i < n; i++){
		current = arr[i];
		flag += 2;
		for(j = i; (j > 0) && (current < arr[j - 1]); j--){
			arr[j] = arr[j-1];
			flag++;
		}
		arr[j] = current;
		flag++;
	}
	printf("\n insertion flag: %i\n", flag);
}


int main(int argc, char **argv){
	int n = 0, *bs_arr, *is_arr, *ss_arr, i = 0, value = 0;
	clock_t ctime;

	if(argc != 2){
		printf("Usage: \"./program n\" (n = array_size)\n");
		return 1;
	}

	n = atoi(argv[1]);
	bs_arr = (int *) malloc(n * sizeof(int));
	ss_arr = (int *) malloc(n * sizeof(int));
	is_arr = (int *) malloc(n * sizeof(int));
	srand(time(NULL));
	for(i = 0; i < n; i++){
		value = rand() % 1000;
		bs_arr[i] = value;
		is_arr[i] = value;
		ss_arr[i] = value;
	}


	ctime = clock(); 
	bubble_sort(bs_arr, n);
	ctime = clock() - ctime;
	printf("bubble sort time: %.3fms\n", (double)ctime/CLOCKS_PER_SEC*1000);

	ctime = clock(); 
	selection_sort(ss_arr, n);
	ctime = clock() - ctime;
	printf("selection sort time: %.3fms\n", (double)ctime/CLOCKS_PER_SEC*1000);

	ctime = clock(); 
	insertion_sort(is_arr, n);
	ctime = clock() - ctime;
	printf("insertion sort time: %.3fms\n", (double)ctime/CLOCKS_PER_SEC*1000);


	return 0;
}
