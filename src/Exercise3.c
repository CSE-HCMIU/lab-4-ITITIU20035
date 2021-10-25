/*
3.	Input an array of n x n (n is even). Sort the first diagonal in
increasing order and the second diagonal in decreasing order.
First diagonal starts with element [0,0], second diagonal starts with elements [n-1,0]
Ex:
_________________________________________________________________
| Input: 4(edge) 10 21 12 53 64 53 86 72 68 99 10 11 12 13 14 15 |
| The converted 2D array will be like this:                      |
| 10 21 12 53                                                    |
| 64 53 86 72                                                    |
| 68 99 10 11                                                    |
| 12 13 14 15                                                    |
| Output:                                                        |
| 10 21 12 12                                                    |
| 64 10 53 72                                                    |
| 68 86 15 11                                                    |
| 99 13 14 53                                                    |
|________________________________________________________________|
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

void Array2Dconverter(int arr[], int a[SIZE][SIZE], int m, int n)
{
	int row, column;
	int counter = 0;
	//Convert 1D array to 2D array
	for (row = 0; row <= (m - 1); row ++){
		for (column = 0; column <= (n - 1); column ++){
			a[row][column] = arr[counter];
			counter++;
		}
	}
}

void printArray(int a[SIZE][SIZE], int m, int n)
{
	int row, column;

	for (row = 0; row <= (m - 1); row ++){
		for (column = 0; column <= (n - 1); column ++){
			printf("%d ", a[row][column]);
		}
		printf("\n");
	}
}

void Ex3(int in_arr[], int n){
	int a[SIZE][SIZE];
	Array2Dconverter(in_arr,a,n,n);
	//Your codes here
	for(int n1 = 0; n1<n; n1++)
	for(int n2 = n1+1; n2<n; n2++){
		if(a[n2][n2] < a[n1][n1]){
			int temp = a[n2][n2];
			a[n2][n2] = a[n1][n1];
				a[n1][n1] =temp;
		}	
		if(a[n2][n-1-n2] < a[n1][n-1-n1]){
				int temp = a[n2][n-1-n2];
				a[n2][n-1-n2] = a[n1][n-1-n1];
				a[n1][n-1-n1] = temp;
		}
	}
	printArray(a,n,n);
}

int main(int argc, char *argv[]) {
	//testing variable, applying it to your algorithm for auto-evaluating
	int edge = atoi(argv[1]);
	argc-=2;
	int testcase[argc],i;
	for(i=0; i<argc;i++){
		testcase[i] = atoi(argv[i+2]);
	}

	Ex3(testcase, edge);
	
	return 0;
}
