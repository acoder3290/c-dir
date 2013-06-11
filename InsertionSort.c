#include <stdio.h>

void insertionSort(int A[],int length)
{
	int i,j,key;
	for(i=1;i<length;i++){
		key = A[i];
		j=i-1;
		while(j>=0 && A[j]>key){
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = key;
	}
}

void printArray(int A[], int length)
{
	int i;
	
	printf("The content of array are");
	for(i=0;i<length;i++){
		printf(" %d",A[i]);
	}
	printf("\n");
}

int main()
{
	int A[] = {5,2,4,6,1,3};
	int length = 6;
	insertionSort(A,length);
	printArray(A, length);
	return 0;
}