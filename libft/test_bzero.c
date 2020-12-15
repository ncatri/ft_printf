#include <stdio.h> 
#include <string.h> 
#include <strings.h> 
#include "libft.h"


void printArray(int arr[], int n) 
{ 
	for (int i=0; i<n; i++) 
		printf("%d ", arr[i]); 
	printf("\n");
} 

int main() 
{ 
	int n = 10; 
	int arr[n]; 

	// Fill whole array with 100. 
	printf("sizeof(arr[0]): %zu\n", sizeof(arr[0]));
	memset(arr, -1, n*sizeof(arr[0])); 
	printf("Array after memset()\n"); 
	printArray(arr, n); 
	ft_bzero(arr, sizeof(int));
	printf("Array after bzero()\n"); 
	printArray(arr, n); 


	return 0; 
} 

