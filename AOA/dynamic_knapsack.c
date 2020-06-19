/*Sahaana Iyer
SE Computer
Batch B
8609*/

#include<stdio.h>
#include<stdlib.h>
int max(int,int);
int main()
{
   int v[20][20]={0},n,i,j,m,p[20]={0},w[20]={0};
   
   printf("Enter total weight of knapsack\n");
   scanf("%d",&m);
   printf("Enter no. of items\n");
   scanf("%d",&n);
   
   printf("Enter their profits\n");
   for(i=1; i<=n; i++)
      scanf("%d",&p[i]);
   printf("Enter their weights\n");
   for(i=1; i<=n; i++)
      scanf("%d",&w[i]);
   
   for(i=1; i<=n; i++)
   {
      for(j=1; j<=m; j++)
      {
          if(w[i]>j)
              v[i][j] = v[i-1][j];
          else
              v[i][j] = max(v[i-1][j], p[i]+v[i-1][j-w[i]]);
      }
   }  
   
   for(i=0; i<=n; i++)
   {
      for(j=0; j<=m; j++)
      {
          printf("%d  ",v[i][j]);
      }
      printf("\n");
   }  
   
   printf("Maximum profit is %d\n", v[n][m]);
   i=n;
   j=m;
   while(i>0 || m>0)
   {
      if(v[i][j] != v[i-1][j])
      {
         m=m-w[i];
         printf("Item no. %d = %d kg\n",i,w[i]);
      }
      i=i-1;
   }
   return 0;
}

int max(int a, int b)
{
   if(a>b)
       return a;
   else
       return b;
}

/*OUTPUT :
Enter total weight of knapsack
12
Enter no. of items
5
Enter their profits
18
25
27
10
15
Enter their weights
3
5
4
6
3
0  0  0  0  0  0  0  0  0  0  0  0  0  
0  0  0  18  18  18  18  18  18  18  18  18  18  
0  0  0  18  18  25  25  25  43  43  43  43  43  
0  0  0  18  27  27  27  45  45  52  52  52  70  
0  0  0  18  27  27  27  45  45  52  52  52  70  
0  0  0  18  27  27  33  45  45  52  60  60  70  
Maximum profit is 70
Item no. 3 = 4 kg
Item no. 2 = 5 kg
Item no. 1 = 3 kg
*/

