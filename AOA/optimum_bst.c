#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *left, *right;
};
struct node *ROOT = NULL;

struct node* buildBST(int keys[], int root[][10], int i, int j)
{
	if(i>j)
		return NULL;
	else
	{
		struct node *new = (struct node *)malloc(sizeof(struct node));
		int r = root[i][j] - 1;
		new->info = keys[r];
		new->left = buildBST(keys, root, i, r-1);
		new->right = buildBST(keys, root, r+1, j);
		return new;
	}
}

void Inorder(struct node *t)
{
	if(t!=NULL)
	{
		Inorder(t->left);
		printf("%d\t",t->info);
		Inorder(t->right);
	}
}

void Preorder(struct node *t)
{
	if(t!=NULL)
	{
		printf("%d\t",t->info);
		Preorder(t->left);
		Preorder(t->right);
	}
}

void print_Table(int a[][10], int n, int m)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}
	printf("\n");
}

int optimalbst(int keys[], int freq[], int n, int cost[][10], int root[][10])
{
	int sum[10][10] = {0};
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=i;k<=j;k++)
				sum[i][j] += freq[k];
		}
	}
	printf("Weight Table:\n");
	print_Table(sum, n, n);
    for(int diff=1;diff<=n;diff++)
	{
		for(int i=0;i<=n-diff;i++)
		{
			int j = i + diff - 1;
			int min = 1000;
			for(int k=i;k<=j;k++)
			{
				if(cost[i][k-1] + cost[k+1][j] < min)
				{
					min = cost[i][k-1] + cost[k+1][j];
					root[i][j] = k+1;
				}
			}
			cost[i][j] = min + sum[i][j];
		}
	}
	printf("Cost Table:\n");
	print_Table(cost, n, n);
	printf("Root Table:\n");
	print_Table(root, n, n);
	return cost[0][n-1];
}

int main()
{
	int keys[] = {10, 20, 30, 40};
	int freq[] = {4, 2, 6, 3};
	int n = 4;
	int cost[10][10] = {0};
	int root[10][10] = {0};

	printf("Optimal Cost = %d\n", optimalbst(keys, freq, n, cost, root));
	ROOT = buildBST(keys, root, 0, n-1);

	printf("Inorder list:\n");
	Inorder(ROOT);
	printf("\n");
	printf("Preorder list:\n");
	Preorder(ROOT);
	printf("\n");
	return 0;
}

/*OUTPUT:
Weight Table:
4       6       12      15
0       2       8       11
0       0       6       9
0       0       0       3

Cost Table:
4       8       20      26
0       2       10      16
0       0       6       12
0       0       0       3

Root Table:
1       1       3       3
0       2       3       3
0       0       3       3
0       0       0       4

Optimal Cost = 26
Inorder list:
10      20      30      40
Preorder list:
30      10      20      40   */
