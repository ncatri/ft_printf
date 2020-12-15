#include <stdio.h> 
#include <string.h> 
#include <strings.h> 
#include "libft.h"

void *ft_memset(void *s, int c, size_t n);

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

	// Fill whole array with value. 
	ft_memset(arr, -1, n*sizeof(arr[0])); 
	printf("Array after memset()\n"); 
	printArray(arr, n); 

	return 0; 
} 

