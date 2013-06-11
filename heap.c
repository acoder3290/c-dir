#include <stdio.h>

void swap(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void max_heapify(int A[], int i, int size)
{
	int l,r,largest;
	
	l = 2*i+1;
	r = 2*(i+1);
	
	if(l<size && A[l]>A[i]) largest = l;
	else largest = i;
	
	if(r<size && A[r]>A[largest]) largest = r;	
	
	if(largest != i){
		swap(&A[i], &A[largest]);
		max_heapify(A,largest,size);
	}else return;
}

void build_max_heap(int A[],int size)
{
	//for a complete binary tree from n/2 to n-1 are all leaves
	int half_size = size/2,i;
	
	for(i=half_size-1;i>=0;i--){
		max_heapify(A,i,size);
	}
}
int main()
{
	int A[] = {4,1,3,2,16,9,10,14,8,7};
	int size = 10,i;
	
	build_max_heap(A,size);
	
	printf("\n");
	for(i=0;i<size;i++){
		printf("%d ",A[i]);
	}
	printf("\n");
	return 0;
}