/*Sahaana Iyer
SE Comp
Batch B
8609*/

#include<stdio.h>
#include<stdlib.h>
int min(int[],int[],int);
int full(int[],int);
int main()
{
	int G[10][10],d[10]={9999},p[10]={0},V[10]={0},NV[10]={1},n,s,e,u,v,i,j;
	printf("Enter the number of nodes\n");
	scanf("%d",&n);
	printf("Enter the number of edges\n");
	scanf("%d",&e);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
			{
				G[i][j]=0;
			}
			else
			{
				G[i][j]=9999;
			}
		}
	}
	for(i=0;i<e;i++)
	{
		printf("Enter source and destination\n");
		scanf("%d%d",&u,&v);
		printf("Enter the weight\n");
		scanf("%d",&G[u][v]);
	}
	printf("Enter the source node\n");
	scanf("%d",&s);
printf("The graph is\n");
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
		printf("%d\t",G[i][j]);
	printf("\n");
}
printf("\n");
	for(i=0;i<n;i++)
	{
		d[i]=G[s][i];
		p[i]=s;
	}
 
	for(i=0;i<n;i++)
	{
		NV[i]=1;
		V[i]=0;
	}
	printf("\n");
	V[s]=1;
	NV[s]=0;
 
	while(!full(V,n))
	{
		u=min(d,NV,n);
		V[u]=1;
		NV[u]=0;
		for(j=0;j<n;j++)
		{
			if(G[u][j]!=0 && G[u][j]!=9999 && V[j]!=1)
			{
				if(d[j]>d[u]+G[u][j])
				{
					d[j]=d[u]+G[u][j];
					p[j]=u;
				}
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d\t",d[i]);
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",p[i]);
	}
}

int min(int d[],int NV[],int n)
{
	int i,j,m;
	for(i=0;i<n;i++)
	{
		if(NV[i]==1)
		{
			m=i;
			break;
		}
	}
	for(j=i+1;j<n;j++)
	{
		if(NV[j]==1)
		{
			if(d[m]>d[j])
			{
				m=j;
			}
		}
	}
	return m;
}

int full(int V[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(V[i]==0)
		{
			return 0;
		}
	}
	return 1;
}
/* OUTPUT :
Enter the number of nodes
5
Enter the number of edges
6
Enter source and destination
0
4
Enter the weight
2
Enter source and destination
0
1
Enter the weight
3
Enter source and destination
0
3
Enter the weight
4
Enter source and destination
1
2
Enter the weight
1
Enter source and destination
2
4
Enter the weight
5
Enter source and destination
3
4
Enter the weight
1
Enter the source node
0
The graph is
0       3       9999    4       2
9999    0       1       9999    9999
9999    9999    0       9999    5
9999    9999    9999    0       1
9999    9999    9999    9999    0


0       3       4       4       2
0       0       1       0       0  */
