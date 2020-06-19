/*Sahaana Iyer
SE Comp
Batch B
8609*/

#include<stdio.h>
#include<stdlib.h>

void prim(int weight[][10], int n)
{
	int MST[10]={0};
	int total_cost=0;
	int u, v, k, i, j, min;

	MST[0] = 1;	

	for(k=0;k<n-1;k++)
	{	
		min = 1000;	
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				//if edge exists, check if node is visted but the other is not (to prevent cycle)
				if(weight[i][j] && ((MST[i] && !MST[j]) || (!MST[i] && MST[j])))
				{
					//if the edge has lower cost than current min
					if(weight[i][j] < min)
					{
						min = weight[i][j];
						u = i;
						v = j;
					}
				}
			}
		}
		printf("%d--%d, cost = %d\n",u, v, min);
		//set the nodes as visited
		MST[u] = 1;
		MST[v] = 1;
		total_cost += min;
	}
	printf("\tTotal cost = %d",total_cost);
}

int main()
{
	int n,e,u,v,i,j;
	int G[10][10]={0};

    printf("Enter the number of nodes :\t");
	scanf("%d",&n);
	printf("Enter the number of edges :\t");
	scanf("%d",&e);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			  G[i][j]=9999;
	}
	for(i=0; i<e; i++)
	{
		printf("Enter the source and destination of the edge no. %d :\t",i+1);
	    scanf("%d%d",&u,&v);
	    printf("Enter the weight of edge :\t");
	    scanf("%d",&G[u][v]);
	    G[v][u]=G[u][v];
    }
    printf("The graph is :\n");
    for(i=0;i<n;i++)
    {
	    for(j=0;j<n;j++)
		    printf("%d\t",G[i][j]);
	    printf("\n");
    }
    printf("\n");
	prim(G, n);
	return 0;
}

/* OUTPUT :
Enter the number of nodes :     4
Enter the number of edges :     4
Enter the source and destination of the edge no. 1 :    0  1
Enter the weight of edge :      5
Enter the source and destination of the edge no. 2 :    1  2
Enter the weight of edge :      11
Enter the source and destination of the edge no. 3 :    2  3
Enter the weight of edge :      5
Enter the source and destination of the edge no. 4 :    3  0
Enter the weight of edge :      10
The graph is :
9999    5       9999    10
5       9999    11      9999
9999    11      9999    5
10      9999    5       9999

0--1, cost = 5
0--3, cost = 10
2--3, cost = 5
          Total cost = 20  */
