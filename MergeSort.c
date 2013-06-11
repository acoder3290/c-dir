#include <stdio.h>

void merge(int A[], int startIndexOfLeftArray, int endIndexOfLeftArray, int endIndexOfRigthArray)
{
	int lengthOfLeftArray = endIndexOfLeftArray - startIndexOfLeftArray + 1;
	//printf("\n lengthOfLeftArray %d",lengthOfLeftArray);
	int lengthOfRightArray = endIndexOfRigthArray - endIndexOfLeftArray;
	//printf("\n lengthOfRightArray %d",lengthOfRightArray);
	int tempLeft[lengthOfLeftArray+1], tempRight[lengthOfRightArray+1];
	int i,j,k;
	for(i=0;i<lengthOfLeftArray;i++){
		tempLeft[i] = A[startIndexOfLeftArray + i];
	}
	for(j=0;j<lengthOfRightArray;j++){
		tempRight[j] = A[endIndexOfLeftArray+1+j];
	}
	tempLeft[i]=999999;
	tempRight[j] = 999999;
	i=0,j=0,k=startIndexOfLeftArray;
	while(k<=endIndexOfRigthArray)
	{
		if(tempLeft[i]<=tempRight[j]){
			A[k]=tempLeft[i];
			i++;
		}else{
			A[k] = tempRight[j];
			j++;
		}
		k++;
	}
}


void mergeSort(int A[], int startIndexOfLeftArray, int endIndexOfRigthArray)
{
	if(startIndexOfLeftArray<endIndexOfRigthArray)
	{
		int mid = (startIndexOfLeftArray+endIndexOfRigthArray)/2;
		printf("\n %d",mid);
		mergeSort(A,startIndexOfLeftArray,mid);
		mergeSort(A,mid+1,endIndexOfRigthArray);
		merge(A,startIndexOfLeftArray,mid,endIndexOfRigthArray);
	}
}

int main(){
	int A[9] = {1,5,3,4,2,9,6,8,7};
	
	int p = 0, r = 8,i;
	printf("\n");
	for(i=0;i<=r;i++){
		printf("%d ",A[i]);
	}
	printf("\n");
	mergeSort(A,p,r);
	printf("\n");
	for(i=0;i<=r;i++){
		printf("%d ",A[i]);
	}
	printf("\n");
	return 0;
}