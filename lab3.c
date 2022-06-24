#include <stdio.h>

void matrixData(int firstMatrix[][10], int secondMatrix[][10], int rowFirst, int columnFirst, int rowSecond, int columnSecond);
void multMatrix(int firstMatrix[][10], int secondMatrix[][10], int multResult[][10], int rowFirst, int columnFirst, int rowSecond, int columnSecond);
void display(int mult[][10], int rowFirst, int columnSecond);

int main(){
	int firstMatrix[10][10], secondMatrix[10][10], mult[10][10], rowFirst, columnFirst, rowSecond, columnSecond, i, j, k;

	printf("Enter rows and column for first matrix: \n");
	scanf("%d %d", &rowFirst, &columnFirst);

	printf("Enter rows and column for second matrix: \n");
	scanf("%d %d", &rowSecond, &columnSecond);

	// If colum of first matrix in not equal to row of second matrix, asking user to enter the size of matrix again.
	while (columnFirst != rowSecond){
		printf("Error! column of first matrix not equal to row of second.\n");
		printf("Enter rows and column for first matrix: \n");
		scanf("%d%d", &rowFirst, &columnFirst);
		printf("Enter rows and column for second matrix: \n");
		scanf("%d%d", &rowSecond, &columnSecond);
	}

	    // Function to take matrices data
        matrixData(firstMatrix, secondMatrix, rowFirst, columnFirst, rowSecond, columnSecond);

        // Function to multiply two matrices.
        multMatrix(firstMatrix, secondMatrix, mult, rowFirst, columnFirst, rowSecond, columnSecond);

        // Function to display resultant matrix after multiplication.
        display(mult, rowFirst, columnSecond);

	return 0;
}

void matrixData(int firstMatrix[][10], int secondMatrix[][10], int rowFirst, int columnFirst, int rowSecond, int columnSecond){
	int i, j;
	printf("\nRemember, we are looking for a sparse matrix which are matrices in which the majority of the entries are zero\n");
	printf("\nEnter elements of matrix 1:\n");
	for(i = 0; i < rowFirst; ++i){
		for(j = 0; j < columnFirst; ++j){
			printf("Enter elements a%d%d: ", i + 1, j + 1);
			scanf("%d", &firstMatrix[i][j]);
		}
	}

	printf("\nEnter elements of matrix 2:\n");
	for(i = 0; i < rowSecond; ++i){
		for(j = 0; j < columnSecond; ++j){
			printf("Enter elements b%d%d: ", i + 1, j + 1);
			scanf("%d", &secondMatrix[i][j]);
		}
	}
}

void multMatrix(int firstMatrix[][10], int secondMatrix[][10], int mult[][10], int rowFirst, int columnFirst, int rowSecond, int columnSecond){
	int i, j, k;

	//Mult elementes initializing to zero
	for(i = 0; i < rowFirst; ++i){
		for(j = 0; j < columnSecond; ++j){
			mult[i][j] = 0;
		}
	}

	//Multiplication of Matrix1 and Matrix2 and saving the result in the Array Mult..
	for(i = 0; i < rowFirst; ++i){
		for(j = 0; j < columnSecond; ++j){
			for(k=0; k<columnFirst; ++k){
				mult[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
			}
		}
	}
}

void display(int mult[][10], int rowFirst, int columnSecond){
	int i, j;
	printf("\nResultant Matrix:\n");
	for(i = 0; i < rowFirst; ++i){
		for(j = 0; j < columnSecond; ++j){
			printf("%d  ", mult[i][j]);
			if(j == columnSecond - 1)
				printf("\n\n");
		}
	}
}