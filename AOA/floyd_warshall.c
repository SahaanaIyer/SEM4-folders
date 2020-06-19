/*Sahaana Iyer
SE Comp
Batch B
8609*/

#include<stdio.h>
#include<stdlib.h>

void path(int S[][10], int i, int j)
{
	if(S[i][j]==j)
	{
		printf("->%d",S[i][j]);
		return;
	}
	else
	{
		path(S,i,S[i][j]);
		printf("->%d",j);
	}
}

int main()
{
	int n,e,u,v,i,j,k;
	int G[10][10]={0}, S[10][10]={0};

    printf("Enter the number of nodes :\t");
	scanf("%d",&n);
	printf("Enter the number of edges :\t");
	scanf("%d",&e);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
				G[i][j]=0;
			else
				G[i][j]=9999;
		}
	}
	for(i=0; i<e; i++)
	{
		printf("Enter the source and destination of the edge no. %d :\t",i+1);
	    scanf("%d%d",&u,&v);
	    printf("Enter the weight of edge :\t");
	    scanf("%d",&G[u][v]);
    }
    printf("The graph is :\n");
    for(i=0;i<n;i++)
    {
	    for(j=0;j<n;j++)
		    printf("%d\t",G[i][j]);
	    printf("\n");
    }
    printf("\n");
    for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i!=j)
				S[i][j]=j;
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			{
				if(j!=i && k!=i && j!=k)
				{
					if(G[j][k]>G[j][i]+G[i][k])
					{
						G[j][k]=G[j][i]+G[i][k];
						S[j][k]=i;
					}
				}
			}
		}
	}
	printf("The graph is : \n");
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		    printf("%d\t",G[i][j]);
		printf("\n");
	}
   	printf("The path is : \n");
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		    printf("%d\t",S[i][j]);
		printf("\n");
	}
	printf("Edges\t   Cost\t     Path\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i!=j)
			{
				printf("(%d,%d)\t   %d\t    %d",i,j,G[i][j],i);
				path(S,i,j);
				printf("\n");
			}
		}
	}    
	return 0;
}
/* OUTPUT :
Enter the number of nodes :     4
Enter the number of edges :     7
Enter the source and destination of the edge no. 1 :    0
1
Enter the weight of edge :      3
Enter the source and destination of the edge no. 2 :    1
0
Enter the weight of edge :      8
Enter the source and destination of the edge no. 3 :    1
2
Enter the weight of edge :      2
Enter the source and destination of the edge no. 4 :    2
0
Enter the weight of edge :      5
Enter the source and destination of the edge no. 5 :    0
3
Enter the weight of edge :      7
Enter the source and destination of the edge no. 6 :    3
0
Enter the weight of edge :      2
Enter the source and destination of the edge no. 7 :    2
3
Enter the weight of edge :      1
The graph is :
0       3       9999    7
8       0       2       9999
5       9999    0       1
2       9999    9999    0

The graph is :
0       3       5       6
5       0       2       3
3       6       0       1
2       5       7       0
The path is :
0       1       1       2
3       0       2       2
3       3       0       3
0       0       1       0
Edges     Cost      Path
(0,1)      3        0->1
(0,2)      5        0->1->2
(0,3)      6        0->1->2->3
(1,0)      5        1->2->3->0
(1,2)      2        1->2
(1,3)      3        1->2->3
(2,0)      3        2->3->0
(2,1)      6        2->3->1
(2,3)      1        2->3
(3,0)      2        3->0
(3,1)      5        3->0->1
(3,2)      7        3->0->1->2   */
