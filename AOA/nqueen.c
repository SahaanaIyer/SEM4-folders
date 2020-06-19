/*Sahaana Iyer
SE Computer
Batch B
8609*/

#include<stdio.h>
#define N 4

int place(int board[][10], int row, int col)
{
	int i, j;
	for(i=0;i<row;i++)
	{
		if(board[i][col])
			return 0;
	}
	for(i=row, j=col;i>=0 && j>=0;i--, j--)
	{
		if(board[i][j])
			return 0;
	}
	for(i=row, j=col;i>=0 && j<N;i--, j++)
	{
		if(board[i][j])
			return 0;
	}
	return 1;
}

void print_column(int col[])
{
	static int k = 1;
	int i;
	printf("Solution %d : \t",k++);
	for(i=0;i<N;i++)
		printf("%d\t",col[i]);
	printf("\n");
}

void nqueen(int board[][10], int col[], int q)
{
	int i;
	if(q==N)
	{
		print_column(col);
		return;
	}

	for(i=0;i<N;i++)
	{
		if(place(board, q, i))
		{
			board[q][i] = 1;
			col[q] = i+1;
			nqueen(board, col, q+1);
			board[q][i] = 0;
		}
	}
}

int main()
{
	int board[10][10]={0};
	int col[10]={0};
	if(N<4)
		printf("Solution does not exist.\n");
	else
		nqueen(board, col, 0);
	return 0;
}

/* OUTPUT:
Solution 1 :    2       4       1       3
Solution 2 :    3       1       4       2   */
