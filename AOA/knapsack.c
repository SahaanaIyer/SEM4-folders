/*Sahaana Iyer
SE Computer
Batch B
8609*/

#include<stdio.h>
void sort(float [], float[], int[], int);

int main()
{
   int n, p[50], i=0, j;
   float pw[50], tp=0.0, u, M, w[50], x[50];
   printf("Enter total weight of knapsack\n");
   scanf("%f",&M);
   u=M;
   printf("Enter no. of items\n");
   scanf("%d",&n);
   printf("Enter their profits\n");
   for(i=0; i<n; i++)
   {
      scanf("%d",&p[i]);
   }
    printf("Enter their weights\n");
   for(i=0; i<n; i++)
   {
      scanf("%f",&w[i]);
   }
   for(i=0; i<n; i++)
   {
      pw[i]=p[i]/w[i];
   }
   sort(pw,w,p,n);
   i=0;
   while(u>0.0  && i<n)
   {
      if(w[i]<u)
      {
          x[i]=1.0;
          u=u-w[i];
          i++;
      }
      else
      {
          x[i]=u/w[i];
          u=0.0;
      }
   }
   for(j=0; j<=i; j++)
   {
      tp=tp+x[j]*p[j];
   }
   printf("Total profit of the knapsack is %f\n",tp);
   printf("The empty space of knapsack is %f\n",u);
   printf("Proportion of items fitted in the sack are :\n");
   printf("Item No. \t Profit/Weight \n");
   for(i=0; i<n; i++)
   {
      printf("%d\t%f\n",i,pw[i]);
   }
   return 0;
}

void sort(float pw[], float w[], int p[], int n)
{
    int i, key, j, temp;
    float t;
    for (i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
           if(pw[i]<pw[j])
           {
               t=pw[i];
               pw[i]=pw[j];
               pw[j]=t;
 
               t=w[i];
               w[i]=w[j];
               w[j]=t;
 
               temp=p[i];
               p[i]=p[j];
               p[j]=temp;
           }
        }
    }
}

/*OUTPUT :
Enter total weight of knapsack
50.0
Enter no. of items
3
Enter their profits
60 100 120
Enter their weights
10.0 20.0 30.0
Total profit of the knapsack is 240.000000
The empty space of knapsack is 0.000000
Proportion of items fitted in the sack are :
Item No.    Profit/Weight
0             6.000000
1             5.000000
2             4.000000
*/

