/*Sahaana Iyer
SE Comp
Batch B
8609*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int G[10][10], d[10]={9999}, p[10]={0}, D[10]={9999}, P[10]={0}, U[10]={0}, V[10]={0}, w[10]={0};
	int i,j,n,u,v,e,src,flag=0;
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
	    U[i]=u;
	    V[i]=v;
	    printf("Enter the weight of edge :\t");
	    scanf("%d",&G[u][v]);
	    w[i]=G[u][v];
	}
	printf("The edges are :\n");
	for(i=0; i<e; i++)
		printf("(%d, %d) = %d\n",U[i],V[i],w[i]);
    printf("The graph is :\n");
    for(i=0;i<n;i++)
    {
	    for(j=0;j<n;j++)
		    printf("%d\t",G[i][j]);
	    printf("\n");
    }
    printf("\n");
	printf("Enter source node :\t");
	scanf("%d",&src);
	
	for(i=0; i<n; i++)
	{
		d[i]=G[src][i];
		p[i]=src;
	}
	
	for(i=0; i<n; i++)
		printf("Dist : %d\t", d[i]);
	printf("\n");
	for(i=0; i<n; i++)
		printf("Pred : %d\t", p[i]);
	
	for(j=0; j<n; j++)
	{
	   for(i=0; i<e; i++)
	   {
		   u=U[i];
		   v=V[i];
		   if(d[u]+G[u][v] < d[v])
		   {
			   d[v]=d[u]+G[u][v];
			   p[v]=u;
		   }
	   }
	   printf("\n");
	   for(i=0; i<n; i++)
	   {
		   printf("Dist : %d\t", d[i]);
		   D[i]=d[i];
	   }
	   printf("\n");
	   for(i=0; i<n; i++)
	   {
		   printf("Pred : %d\t", p[i]);
		   P[i]=p[i];
	   }
    }
      
	for(i=0; i<e; i++)
	{
		u=U[i];
		v=V[i];
		if(d[u]+G[u][v] < d[v])
		{
		    d[v]=d[u]+G[u][v];
			p[v]=u;
		}
	}	
	for(i=0; i<n; i++)
	{
		if(D[i]!=d[i])
		{
		    flag=1;
		    break;
	    }
    }
	if(flag==1)
	    printf("Algo insufficient. Shortest path not found\n");
	else
	   {
	  	   printf("\nThe shortest distance is : \n");
	  	   for(i=0; i<n; i++)
		      printf("Dist : %d\t", d[i]);
	   }
	return 0;
}
/* OUTPUT :
Enter the number of nodes :     4
Enter the number of edges :     6
Enter the source and destination of the edge no. 1 :    0  1
Enter the weight of edge :      5
Enter the source and destination of the edge no. 2 :    1  0
Enter the weight of edge :      3
Enter the source and destination of the edge no. 3 :    0  2
Enter the weight of edge :      2
Enter the source and destination of the edge no. 4 :    3  0
Enter the weight of edge :      -1
Enter the source and destination of the edge no. 5 :    1  3
Enter the weight of edge :      4
Enter the source and destination of the edge no. 6 :    2  3
Enter the weight of edge :      6
The edges are :
(0, 1) = 5
(1, 0) = 3
(0, 2) = 2
(3, 0) = -1
(1, 3) = 4
(2, 3) = 6
The graph is :
0       5       2       9999
3       0       9999    4
9999    9999    0       6
-1      9999    9999    0

Enter source node :     0
Dist : 0        Dist : 5        Dist : 2        Dist : 9999
Pred : 0        Pred : 0        Pred : 0        Pred : 0
Dist : 0        Dist : 5        Dist : 2        Dist : 8
Pred : 0        Pred : 0        Pred : 0        Pred : 2
Dist : 0        Dist : 5        Dist : 2        Dist : 8
Pred : 0        Pred : 0        Pred : 0        Pred : 2
Dist : 0        Dist : 5        Dist : 2        Dist : 8
Pred : 0        Pred : 0        Pred : 0        Pred : 2
Dist : 0        Dist : 5        Dist : 2        Dist : 8
Pred : 0        Pred : 0        Pred : 0        Pred : 2
The shortest distance is :
Dist : 0        Dist : 5        Dist : 2        Dist : 8   */
