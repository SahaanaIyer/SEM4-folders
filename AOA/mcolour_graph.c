/*Sahaana Iyer
SE Computer
Batch B
8609*/

#include<stdio.h>
#define N 4
#define M 3

int can_color(int graph[][10], int solution[], int node, int i)
{
	int j;
	for(j=0;j<node;j++)
	{
		if(graph[node][j] == 1 && solution[j] == i)
			return 0;
	}
	return 1;
}

void print_combination(int solution[], char colors[])
{
	int i;
	printf("%c", colors[solution[0]-1]);
	for(i=1;i<N;i++)
		printf(", %c", colors[solution[i]-1]);
	printf("\n");
}

int coloring(int graph[][10], char colors[], int solution[], int node)
{
	static int flag = 0;
	int i;
	if(node == N)
	{
		print_combination(solution, colors);
		flag = 1;
		return 1;
	}
	else
	{
		for(i=1;i<=M;i++)
		{
			if(can_color(graph, solution, node, i))
			{
				solution[node] = i; 
				coloring(graph, colors, solution, node + 1);
				solution[node] = 0; 
			}
		}
		return flag;
	}
}

int main()
{
	int e,n,u,v,i,j;
	int G[10][10]={0};
	printf("Enter the number of nodes\n");
	scanf("%d",&n);
	printf("Enter the number of edges\n");
	scanf("%d",&e);
	
	for(i=0;i<e;i++)
	{
		printf("Enter source and destination\n");
		scanf("%d%d",&u,&v);
		G[u][v]=1;
	}

    printf("The graph is\n");
    for(i=0;i<n;i++)
    {
	    for(j=0;j<n;j++)
		    printf("%d\t",G[i][j]);
	    printf("\n");
    }
    printf("\n");
	int solution[10] = {0};
	char colors[] = {'R', 'G', 'B'};
	if(!coloring(G, colors, solution, 0))
		printf("Graph coloring not possible.\n");
	return 0;
}
/*OUTPUT :
Enter the number of nodes
4
Enter the number of edges
4
Enter source and destination
0
1
Enter source and destination
1
2
Enter source and destination
2
3
Enter source and destination
3
0
The graph is
0       1       0       0
0       0       1       0
0       0       0       1
1       0       0       0

R, R, R, G
R, R, R, B
R, R, G, G
R, R, G, B
R, R, B, G
R, R, B, B
R, G, R, G
R, G, R, B
R, G, G, G
R, G, G, B
R, G, B, G
R, G, B, B
R, B, R, G
R, B, R, B
R, B, G, G
R, B, G, B
R, B, B, G
R, B, B, B
G, R, R, R
G, R, R, B
G, R, G, R
G, R, G, B
G, R, B, R
G, R, B, B
G, G, R, R
G, G, R, B
G, G, G, R
G, G, G, B
G, G, B, R
G, G, B, B
G, B, R, R
G, B, R, B
G, B, G, R
G, B, G, B
G, B, B, R
G, B, B, B
B, R, R, R
B, R, R, G
B, R, G, R
B, R, G, G
B, R, B, R
B, R, B, G
B, G, R, R
B, G, R, G
B, G, G, R
B, G, G, G
B, G, B, R
B, G, B, G
B, B, R, R
B, B, R, G
B, B, G, R
B, B, G, G
B, B, B, R
B, B, B, G     */
